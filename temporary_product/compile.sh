# CC = gcc
# product = -o
#
# windows_flags = -mwindows
#
# case "$OSTYPE" in
#   solaris*) echo "SOLARIS" ;;
#   darwin*)  echo "OSX" ;;
#   linux*)   echo "LINUX" ;;
#   bsd*)     echo "BSD" ;;
#   *)        echo "unknown: $OSTYPE" ;;
# esac

gcc main.c -o ./product/main.exe -mwindows -lopengl32
