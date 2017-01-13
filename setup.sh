if [ -z "$IGUANA_HOME" ]; then
    echo "Error: IGUANA_HOME environement variable not set"
    exit 1
fi
if [ -z "$IGUANA_CASESTUDIES_HOME" ]; then
    echo "Error: IGUANA_CASESTUDIES_HOME environement variable not set"
    exit 1
fi

# Make the case study C code symlink
cd $IGUANA_HOME
if [ -h casestudies ]
  then
    rm casestudies
fi
ln -s $IGUANA_CASESTUDIES_HOME/c casestudies

# Make the case study Java code symlink
cd $IGUANA_HOME/src/main/java/org/iguanatool/
if [ -h casestudies ]
  then
    rm casestudies
fi
ln -s $IGUANA_CASESTUDIES_HOME/java casestudies

# This is for any specific case study or experimental Java code to be compiled into IGUANA
# It appears in the "iguana" directory in this repo and maps to org/iguanatool/ext
# (That is, all code should be in the package org.iguanatool.ext or a subpackage.)
if [ -h ext ]
  then
    rm ext
fi
ln -s $IGUANA_CASESTUDIES_HOME/iguana ext
