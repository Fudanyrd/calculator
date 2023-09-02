makethis(){
    if ["$1" -ne "false"]; then
        rm -r build
    fi
    cmake -B build
    cmake --build build
    echo "Done."
}

#this piece of script can call cmake and compile this project.
#you can decide whether to delete the folder /build
#yes: run "source makethis.sh; makethis true"
#no:  run "source makethis.sh; makethis false"