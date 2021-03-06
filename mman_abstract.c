#ifdef _WIN32

	#define LENGTH_TYPE				SIZE_T
	#define ADDRESS_TYPE			LPVOID
	#define PROTECTION_TYPE		DWORD
	#define ERROR_TYPE				DWORD
	#define SUCCESS_TYPE			BOOL

	#define MAP_FAILED				NULL
	#define PROTECT_FAILED		0

#else

	#define LENGTH_TYPE				size_t
	#define ADDRESS_TYPE			void*
	#define PROTECTION_TYPE		int
	#define ERROR_TYPE				int
	#define SUCCESS_TYPE			int

	#define PROTECT_FAILED		-1

#endif

struct memory
{
	ADDRESS_TYPE address;
	LENGTH_TYPE length;
	PROTECTION_TYPE protection;
};

#ifdef _WIN32

	#define PAGE_EXECUTE_WRITE	PAGE_EXECUTE_WRITECOPY
	#define PAGE_WRITE 			PAGE_WRITECOPY

	//	https://msdn.microsoft.com/en-us/library/windows/desktop/aa366887(v=vs.85).aspx
	ADDRESS_TYPE WINAPI MAP(struct memory* m, LENGTH_TYPE length, PROTECTION_TYPE protection)
	{
		return m->address = VirtualAlloc(NULL, m->length = length, MEM_COMMIT, m->protection = protection);
	}

	// https://msdn.microsoft.com/en-us/library/windows/desktop/aa366892(v=vs.85).aspx
	SUCCESS_TYPE WINAPI UNMAP(struct memory* m)
	{
		SUCCESS_TYPE status = VirtualFree(m->address, 0, MEM_RELEASE);
		return status;
	}

	// https://msdn.microsoft.com/en-us/library/windows/desktop/aa366898(v=vs.85).aspx
	SUCCESS_TYPE WINAPI PROTECT(struct memory* m, PROTECTION_TYPE protection)
	{
		DWORD trash;
		return VirtualProtect(m->address, m->length, m->protection = protection, &trash);
	}

	ERROR_TYPE WINAPI GET_LAST_ERROR()
	{
		return GetLastError();
	}

#else

	#define PAGE_NOACCESS				PROT_NONE
	#define PAGE_EXECUTE				PROT_EXEC
	#define PAGE_EXECUTE_READ			PROT_EXEC|PROT_READ
	#define PAGE_EXECUTE_READWRITE			PROT_EXEC|PROT_READ|PROT_WRITE
	#define PAGE_EXECUTE_WRITECOPY			PROT_EXEC|PROT_WRITE
	#define PAGE_EXECUTE_WRITE			PROT_EXEC|PROT_WRITE
	#define PAGE_READONLY				PROT_READ
	#define PAGE_READWRITE				PROT_READ|PROT_WRITE
	#define PAGE_WRITECOPY				PROT_WRITE
	#define PAGE_WRITE				PROT_WRITE

	//	http://man7.org/linux/man-pages/man2/mmap.2.html
	ADDRESS_TYPE MAP(struct memory* m, LENGTH_TYPE length, PROTECTION_TYPE protection)
	{
		return m->address = mmap(0, m->length = length, m->protection = protection, MAP_ANONYMOUS, -1, 0);
	}

	SUCCESS_TYPE UNMAP(struct memory* m)
	{
		SUCCESS_TYPE status = munmap(m->address, m->length);
		return status;
	}

	// http://man7.org/linux/man-pages/man2/mprotect.2.html
	SUCCESS_TYPE PROTECT(struct memory* m, PROTECTION_TYPE protection)
	{
		return mprotect(m->address, m->length, m->protection = protection);
	}

	ERROR_TYPE GET_LAST_ERROR()
	{
		return errno;
	}

#endif
