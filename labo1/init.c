#include "init.h"
void getplatforms(cl_uint* platforms, cl_platform_id** availablePlatforms) {
	cl_uint err=0;
	err = clGetPlatformIDs(NULL, NULL, platforms);
	size_t test = *platforms * sizeof(cl_platform_id);
	*availablePlatforms = (cl_platform_id*)malloc(*platforms * sizeof(cl_platform_id));
	err = clGetPlatformIDs(*platforms, *availablePlatforms, NULL);
}
void getids(cl_platform_id platformid,cl_uint *devices, cl_device_id** availableDevices) {
	cl_uint err = 0;
	err = clGetDeviceIDs(platformid, CL_DEVICE_TYPE_ALL, NULL, NULL, devices);
	*availableDevices = (cl_device_id*)malloc(*devices * sizeof(cl_device_id));
	err = clGetDeviceIDs(platformid, CL_DEVICE_TYPE_ALL,*devices,*availableDevices,NULL);
}
char* readSource(char*filename) {
	char* source = NULL;
	int length = 0;
	FILE* f = NULL;
	f = fopen(filename, "rb");

	fseek(f,0, SEEK_END);
	length = ftell(f);
	source = (char*)malloc(sizeof(char) * length + 1);
	rewind(f);
	fread(source, sizeof(char), length, f);
	source[length] = '\0';
	return source;
}
void setupCL(oclC *deviceconst,const char *source) {
	cl_int err = 0;
	cl_context test = clCreateContext(NULL, 1, &deviceconst->oclDevice, NULL, NULL, &err);
	deviceconst->oclContext = clCreateContext(NULL, 1, &deviceconst->oclDevice, NULL, NULL, &err);
	deviceconst->oclCommQueue = clCreateCommandQueueWithProperties(deviceconst->oclContext, deviceconst->oclDevice, NULL, &err);
	deviceconst->oclProgram = clCreateProgramWithSource(deviceconst->oclContext, 1, &source, NULL, &err);
}