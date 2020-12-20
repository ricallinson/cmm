# Traverse up in directory tree to find containing folder.
cmm_find_up() {
  local path
  path=$1
  while [ "$path" != "" ] && [ ! -d "$path/$2" ]; do
    path=${path%/*}
  done
  echo "$path"
}

# Find the first parent `src` directory starting at the given directory.
cmm_find_src() {
  local dir
  dir="$(cmm_find_up $1 'src')"
  if [ -e "$dir/src" ]; then
    echo "$dir/src"
  fi
}

# Check if the given directory exists.
cmm_resolve() {
    cd "$1" 2>/dev/null || return $?  # cd to desired directory; if fail, quell any error messages but return exit status
    echo "`pwd -P`" # output full, link-resolved path
}

cmm() {
    case $1 in

    "clean" )
        cmmb clean
    ;;

    "env" )
        echo
        echo "CMMPATH=$CMMPATH"
        echo "GCC=$(which gcc)"
        echo "CMMB=$(which cmmb)"
        echo
    ;;

    "get" )
        echo
        echo "Not implemented yet"
        echo
    ;;

    "help" )
        echo
        echo "C Minus Minus"
        echo
        echo "Usage:"
        echo
        echo "    cmm clean                   remove object files"
        echo "    cmm env                     print C Minus Minus environment information"
        echo "    cmm get                     download and install packages and dependencies"
        echo "    cmm help                    show this message"
        echo "    cmm here                    set the current directory as the C Minus Minus workspace"
        echo "    cmm install                 compile and install packages and dependencies"
        echo "    cmm test                    test packages"
        echo "    cmm version                 print C Minus Minus version"
        echo
    ;;

    "here" )
        local wPath
        if [ -z $2 ]; then
            wPath=$(cmm_find_src $PWD)
            wPath=${wPath%/*}
        else
            wPath="`cmm_resolve \"$2\"`"
        fi
        if [ -z $wPath ]; then
            echo
            echo "This command must be run in a C Minus Minus workspace"
            echo
            return 0
        fi
        mkdir -p $wPath/bin
        mkdir -p $wPath/src
        export CMMPATH=$wPath
        export PATH=$PATH:$CMMPATH/bin

        echo
        echo "Workspace set to $CMMPATH"
        echo
    ;;

    "install" )
        cmmb install "${@:2}"
    ;;

    "test" )
        cmmb test "${@:2}"
    ;;

    "version" )
        echo
        echo "C Minus Minus v0.0.1"
        echo
    ;;

    *)
        echo "cmm: unknown subcommand \"$1\""
        echo "Run 'cmm help' for usage."
        return 1

    esac

    return $?
}
