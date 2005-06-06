#ifndef __KERNELDEFAULTCONFIG__
#define __KERNELDEFAULTCONFIG__

#include <string>

#include "NewSiconosVector.h" // for N_ASCII (...??)

/* A matrix is saved in the XML output file if his size is not higher then MatrixMaxSize */
/*const*/ int   MATRIX_MAX_SIZE = 10;
/*const*/
int   VECTOR_MAX_SIZE = 10;
/*const*/
std::string   FILE_STORAGE = N_ASCII; // N_ASCII or N_BINARY

/*const*/
std::string   XML_SCHEMA = "/share/SICONOS/SiconosModelSchema-V1.2.xsd";

std::string   DefaultSolver = "default";
std::string   DefaultAlgoName = "default";
std::string   DefaultAlgoNormType = "default";
double  DefaultAlgoTolerance = -1.0;
int   DefaultAlgoMaxIter = -1;
double  DefaultAlgoSearchDirection = -1.0;

std::string  DefaultComputeInput = "BasicPlugin:computeInput";
std::string  DefaultComputeOutput = "BasicPlugin:computeOutput";

#endif

