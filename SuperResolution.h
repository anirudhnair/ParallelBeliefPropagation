#pragma once

#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include "pup_stl.h"
#include <cstring>
#include <cassert>
#include <dirent.h>
using namespace std;



// macros and constants 
#define SUCCESS 0
#define FAIL    1
#define CONV_PERIOD 5 // convergence test every CONV_PERIOD
const double TOL = 1.0;
const double SIGMA = 0.5; // need to update to correct value.

//typedefs 
typedef pair<double*,double*> CandidatePair;
typedef vector<CandidatePair> ImageData;
typedef unsigned int PatchID; 
typedef double * Patch;

// utility functions
int GetFilesFromDir(const string &sFolderName, vector<string> &);
double phi(Patch *lhs, Patch *rhs,int size);




struct ImageDB {
  int nImageFiles;
  int lowResSize; 
  int highResSize;
  ImageData imageData;
  ImageDB()
  {
    nImageFiles=lowResSize=highResSize= 0;
  }

  Patch GetLowResPatch(int index)
  {
    if(index < imageData.size())
      return imageData[index].first;
    else 
      return NULL;
  }
  Patch GetHighResPatch(int index)
  {
    if(index < imageData.size())
      return imageData[index].second;
    else
      return NULL;
  }
};

typedef struct {
    int i, j;
    PatchID id;
} patch_t;

typedef ImageData::iterator DBIter;