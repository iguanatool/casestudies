if [ -z "$IGUANA_HOME" ]; then
    echo "Error: IGUANA_HOME environement variable not set"
    exit 1
fi  
if [ -z "$IGUANA_CASESTUDIES_HOME" ]; then
    echo "Error: IGUANA_CASESTUDIES_HOME environement variable not set"
    exit 1
fi  

cd $IGUANA_HOME
ln -s $IGUANA_CASESTUDIES_HOME/c casestudies

cd $IGUANA_HOME/src/main/java/org/iguanatool/
ln -s $IGUANA_CASESTUDIES_HOME/java casestudies
