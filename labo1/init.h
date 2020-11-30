#pragma once
#include <CL\opencl.h>
//VC++directories\library direcories -> D:\openCL\lib;$(LibraryPath)
//C C++/General\additioanl include directories -> D:\openCL\include;%(AdditionalIncludeDirectories)
//linker/all options/additional dependecies opencl.lib;%(AdditionalDependencies)
#include <stdio.h>
#include <stdlib.h>
#pragma once
typedef unsigned __int32 uint32_t;
typedef struct OCLConstructs
{
	cl_device_id oclDevice;
	cl_context oclContext;
	cl_command_queue oclCommQueue;
	cl_program oclProgram;
} oclC;
void getplatforms(cl_uint*, cl_platform_id**);
void getids(cl_platform_id, cl_uint*, cl_device_id**);
char* readSource(char*);
void setupCL(oclC*, char*);