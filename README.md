# IGUANA case studies for the Dependence and Testability Project with Dave Binkley

To use with IGUANA you will need to invoke the `setup.sh` bash script in the root directory of this repo. This requires:

* The `IGUANA_HOME` environment variable to be set to the root directory of IGUANA on your system;
* The `IGUANA_CASESTUDIES_HOME` environment variable to be set to the root directory of wherever you have checked this particular repository out. 

The `setup.sh` script sets up the relevant symlinks so that your IGUANA installation can use the case studies provided by this repository.

Project specific IGUANA (Java) code should be placed in the `iguana` directory, which will be added to IGUANA as the package `org.iguanatool.ext`