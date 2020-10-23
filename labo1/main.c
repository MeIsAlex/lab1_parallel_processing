#include "init.h"
#include "bmpfuncs.h"
#include <stdlib.h>
//lab 1
/*
void runCL(oclC*);
int main() {
	cl_uint err = 0;
	cl_uint platforms = 0;
	cl_uint devices = 0;
	char platformName[150];
	char* source=NULL;
	cl_platform_id *availablePlatforms=NULL;
	cl_device_id* availableDevices = NULL;
	oclC deviceconst;
	getplatforms(&platforms, &availablePlatforms);
	for (int i = 0; i < platforms; i++)
	{
		err = clGetPlatformInfo(availablePlatforms[i], CL_PLATFORM_NAME, 150, platformName, NULL);
		printf("platform %d: %s \n", i + 1, platformName);
		printf("\n");
	}
	getids(availablePlatforms[1], &devices, &availableDevices);
	for (int i = 0; i < devices; i++) {
		cl_device_type type = 0;
		err = clGetDeviceInfo(availableDevices[i], CL_DEVICE_TYPE, sizeof(cl_device_type), &type, NULL);
		switch (type)
		{
		case CL_DEVICE_TYPE_CPU: printf("%d : CPU \n", i + 1);
			break;
		case CL_DEVICE_TYPE_GPU: printf("%d : GPU \n", i + 1);
			break;
		case CL_DEVICE_TYPE_ACCELERATOR: printf("%d : ACCELERATOR \n", i + 1);
			break;
		default: printf("%d : UNKNOWN DEVICE OR DEVICE NOT FOUND",i+1);
			break;
		}
	}
	source = readSource("helloworld.cl");
	deviceconst.oclDevice = availableDevices[0];
	setupCL(&deviceconst,source);
	runCL(&deviceconst);
	return 0;
}
void runCL(oclC* device) {
	cl_uint err=0;
	cl_kernel kernel;
	cl_mem buffer;
	cl_int threads = 1024;
	cl_uint globWorkSz = threads;
	uint32_t* output=0;
	output = (uint32_t*)malloc(sizeof(uint32_t) * threads);
	err = clBuildProgram(device->oclProgram, 1, &device->oclDevice, NULL, NULL, NULL);
	if (err != CL_SUCCESS) {
		printf("error while builing");
	}
	kernel = clCreateKernel(device->oclProgram, "HelloWorld", &err);
	if (err != CL_SUCCESS) {
		printf("error while creating kernel");
	}
	buffer = clCreateBuffer(device->oclContext, CL_MEM_WRITE_ONLY, threads * sizeof(cl_int), NULL, &err);
	if (err != CL_SUCCESS) {
		printf("error while creating buffer");
	}
	err = clSetKernelArg(kernel, 0, sizeof(buffer), (void*)&buffer);
	if (err != CL_SUCCESS) {
		printf("error while setting arg");
	}
	err = clEnqueueNDRangeKernel(device->oclCommQueue, kernel, 1, 0, (const size_t*)&globWorkSz, 0, 0, NULL, NULL);
	if (err != CL_SUCCESS) {
		printf("error while starting kernel");
	}
	clFinish(device->oclCommQueue);
	err = clEnqueueReadBuffer(device->oclCommQueue, buffer, CL_TRUE, 0, sizeof(cl_uint) * threads, output, NULL, NULL, NULL);
	if (err != CL_SUCCESS) {
		printf("error while reading buffer");
	}
	else {
		for (int i = 0; i < threads; i++) {
			printf("%d \n", output[i]);
		}
	}
	clReleaseKernel(kernel);
	clReleaseMemObject(buffer);
	return 0;
}*/
//######################################################################################################################################
/*
void runCL(oclC*);
int main() {
	cl_uint err = 0;
	cl_uint platforms = 0;
	cl_uint devices = 0;
	char platformName[150];
	char* source = NULL;
	cl_platform_id* availablePlatforms = NULL;
	cl_device_id* availableDevices = NULL;
	oclC deviceconst;
	getplatforms(&platforms, &availablePlatforms);
	getids(availablePlatforms[1], &devices, &availableDevices);
	source = readSource("helloworld.cl");
	deviceconst.oclDevice = availableDevices[0];
	setupCL(&deviceconst, source);
	runCL(&deviceconst);
	return 0;
}
void runCL(oclC* device) {
	cl_uint err=0;
	cl_kernel kernel;
	cl_mem buffer;
	cl_mem buffer2;
	char *userinput=NULL,c=NULL;
	int i=0, j=1;
	char* output;
	cl_uint number = 12;
	while (c != '\n') {
		if (c != '\n') {
			c = getc(stdin);
			userinput = (char*)realloc(userinput, j * sizeof(char));
			userinput[i] = c;
			i++;
			j++;
		}
	}
	userinput[i] = '\0';
	number = j;
	output = (char*)malloc(sizeof(char) * number);
	err = clBuildProgram(device->oclProgram, 1, &device->oclDevice, NULL, NULL, NULL);
	kernel = clCreateKernel(device->oclProgram, "HelloWorld1", &err);
	buffer = clCreateBuffer(device->oclContext, CL_MEM_WRITE_ONLY, sizeof(char) * number, NULL, &err);
	buffer2 = clCreateBuffer(device->oclContext, CL_MEM_READ_ONLY, sizeof(char) * number, NULL, &err);
	err = clSetKernelArg(kernel, 0, sizeof(buffer), (void*)&buffer);
	err = clSetKernelArg(kernel, 1, sizeof(buffer2), (void*)&buffer2);
	err = clEnqueueWriteBuffer(device->oclCommQueue, buffer2, CL_TRUE, 0, sizeof(char) * number, userinput, NULL, NULL, NULL);
	err = clEnqueueNDRangeKernel(device->oclCommQueue, kernel, 1, 0, (const size_t*)&number, 0, 0, NULL, NULL);
	err = clEnqueueReadBuffer(device->oclCommQueue, buffer, CL_TRUE, 0, sizeof(char)*number, output, NULL, NULL, NULL);
	if (err != CL_SUCCESS) {
		printf("error while reading buffer");
	}
	else {
		for (int i = 0; i < number; i++) {
			printf("%c", output[i]);
		}
	}
	clReleaseKernel(kernel);
	clReleaseMemObject(buffer);
	return 0;
}*/
//---------------------------------------------------------------------------------------------------------------------------
//lab 2
//oef 1
/*#include <time.h>
#include <stdlib.h>
void runCL(oclC*);
int main() {
	cl_uint err = 0;
	cl_uint platforms = 0;
	cl_uint devices = 0;
	char platformName[150];
	char* source = NULL;
	cl_platform_id* availablePlatforms = NULL;
	cl_device_id* availableDevices = NULL;
	oclC deviceconst;
	getplatforms(&platforms, &availablePlatforms);
	getids(availablePlatforms[1], &devices, &availableDevices);
	source = readSource("helloworld.cl");
	deviceconst.oclDevice = availableDevices[0];
	setupCL(&deviceconst, source);
	runCL(&deviceconst);
	return 0;
}
void runCL(oclC* device) {
	cl_uint err = 0;
	cl_kernel kernel;
	cl_mem buffer;
	cl_mem buffer2;
	cl_mem buffer3;
	int a[5], b[5], c[5];
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		a[i] = rand();
		b[i] = rand();
	}
	err = clBuildProgram(device->oclProgram, 1, &device->oclDevice, NULL, NULL, NULL);
	kernel = clCreateKernel(device->oclProgram, "lab2_oef1", &err);
	buffer = clCreateBuffer(device->oclContext, CL_MEM_WRITE_ONLY, sizeof(a), NULL, &err);
	buffer2 = clCreateBuffer(device->oclContext, CL_MEM_WRITE_ONLY, sizeof(b), NULL, &err);
	buffer3 = clCreateBuffer(device->oclContext, CL_MEM_READ_ONLY, sizeof(c), NULL, &err);
	err = clSetKernelArg(kernel, 0, sizeof(buffer), (void*)&buffer);
	err = clSetKernelArg(kernel, 1, sizeof(buffer2), (void*)&buffer2);
	err = clSetKernelArg(kernel, 2, sizeof(buffer3), (void*)&buffer3);
	err = clEnqueueWriteBuffer(device->oclCommQueue, buffer, CL_TRUE, 0, sizeof(a), a, NULL, NULL, NULL);
	err = clEnqueueWriteBuffer(device->oclCommQueue, buffer2, CL_TRUE, 0, sizeof(b), b, NULL, NULL, NULL);
	err = clEnqueueNDRangeKernel(device->oclCommQueue, kernel, 1, 0, (const size_t*)c, 0, 0, NULL, NULL);
	err = clEnqueueReadBuffer(device->oclCommQueue, buffer3, CL_TRUE, 0, sizeof(c), c, NULL, NULL, NULL);
	if (err != CL_SUCCESS) {
		printf("error while reading buffer");
	}
	else {
		for (int i = 0; i < 5; i++) {
			printf("%d \n", c[i]);
		}
	}
	clReleaseKernel(kernel);
	clReleaseMemObject(buffer);
	return 0;
}*/
//######################################################################################################################################
//oef2
/*
#include <time.h>
#include <stdlib.h>
void runCL(oclC*);
int main() {
	cl_uint err = 0;
	cl_uint platforms = 0;
	cl_uint devices = 0;
	char* source = NULL;
	cl_platform_id* availablePlatforms = NULL;
	cl_device_id* availableDevices = NULL;
	oclC deviceconst;
	getplatforms(&platforms, &availablePlatforms);
	getids(availablePlatforms[1], &devices, &availableDevices);
	source = readSource("helloworld.cl");
	deviceconst.oclDevice = availableDevices[0];
	setupCL(&deviceconst, source);
	runCL(&deviceconst);
	return 0;
}
void runCL(oclC* device) {
	cl_uint err = 0;
	cl_kernel kernel;
	cl_mem buffer;
	cl_mem buffer2;
	cl_mem buffer3;
	cl_mem buffer4;
	int a[5][5], b[5][5], c[5][5];
	int w = 5;
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		for (int y = 0; y < 5; y++) {
			a[i][y] = rand();
			b[i][y] = rand();
		}
	}
	err = clBuildProgram(device->oclProgram, 1, &device->oclDevice, NULL, NULL, NULL);
	kernel = clCreateKernel(device->oclProgram, "lab2_oef2", &err);
	buffer = clCreateBuffer(device->oclContext, CL_MEM_WRITE_ONLY, sizeof(a), NULL, &err);
	buffer2 = clCreateBuffer(device->oclContext, CL_MEM_WRITE_ONLY, sizeof(b), NULL, &err);
	buffer4 = clCreateBuffer(device->oclContext, CL_MEM_WRITE_ONLY, sizeof(int), NULL, &err);
	buffer3 = clCreateBuffer(device->oclContext, CL_MEM_READ_ONLY, sizeof(c), NULL, &err);
	err = clSetKernelArg(kernel, 0, sizeof(buffer), (void*)&buffer);
	err = clSetKernelArg(kernel, 1, sizeof(buffer2), (void*)&buffer2);
	err = clSetKernelArg(kernel, 2, sizeof(buffer3), (void*)&buffer3);
	err = clSetKernelArg(kernel, 3, sizeof(buffer4), (void*)&buffer4);
	err = clEnqueueWriteBuffer(device->oclCommQueue, buffer, CL_TRUE, 0, sizeof(a), a, NULL, NULL, NULL);
	err = clEnqueueWriteBuffer(device->oclCommQueue, buffer2, CL_TRUE, 0, sizeof(b), b, NULL, NULL, NULL);
	err = clEnqueueWriteBuffer(device->oclCommQueue, buffer4, CL_TRUE, 0, sizeof(int), &w, NULL, NULL, NULL);
	err = clEnqueueNDRangeKernel(device->oclCommQueue, kernel, 2, 0, (const size_t*)c, 0, 0, NULL, NULL);
	err = clEnqueueReadBuffer(device->oclCommQueue, buffer3, CL_TRUE, 0, sizeof(c), c, NULL, NULL, NULL);
	if (err != CL_SUCCESS) {
		printf("error while reading buffer");
	}
	else {
		for (int i = 0; i < 25; i++) {
			printf("%d, ", c[i]);
			if (((i + 1) % 5) == 0) {
				printf("\n");
			}
		}
	}
	clReleaseKernel(kernel);
	clReleaseMemObject(buffer);
	return 0;
}
*/
//oef 3
/*
#include <time.h>
#include <stdlib.h>
void runCL(oclC*);
int main() {
	cl_uint err = 0;
	cl_uint platforms = 0;
	cl_uint devices = 0;
	char* source = NULL;
	cl_platform_id* availablePlatforms = NULL;
	cl_device_id* availableDevices = NULL;
	oclC deviceconst;
	getplatforms(&platforms, &availablePlatforms);
	getids(availablePlatforms[1], &devices, &availableDevices);
	source = readSource("helloworld.cl");
	deviceconst.oclDevice = availableDevices[0];
	setupCL(&deviceconst, source);
	runCL(&deviceconst);
	return 0;
}
void runCL(oclC* device) {
	cl_uint err = 0;
	cl_kernel kernel;
	cl_mem buffer;
	cl_mem buffer2;
	cl_mem buffer3;
	int a[5], b[5], c[5];
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		a[i] = rand()%50;
		b[i] = rand()%50;
	}
	err = clBuildProgram(device->oclProgram, 1, &device->oclDevice, NULL, NULL, NULL);
	kernel = clCreateKernel(device->oclProgram, "lab2_oef3", &err);
	buffer = clCreateBuffer(device->oclContext, CL_MEM_WRITE_ONLY, sizeof(a), NULL, &err);
	buffer2 = clCreateBuffer(device->oclContext, CL_MEM_WRITE_ONLY, sizeof(b), NULL, &err);
	buffer3 = clCreateBuffer(device->oclContext, CL_MEM_READ_ONLY, sizeof(c), NULL, &err);
	err = clSetKernelArg(kernel, 0, sizeof(buffer), (void*)&buffer);
	err = clSetKernelArg(kernel, 1, sizeof(buffer2), (void*)&buffer2);
	err = clSetKernelArg(kernel, 2, sizeof(buffer3), (void*)&buffer3);
	err = clEnqueueWriteBuffer(device->oclCommQueue, buffer, CL_TRUE, 0, sizeof(a), a, NULL, NULL, NULL);
	err = clEnqueueWriteBuffer(device->oclCommQueue, buffer2, CL_TRUE, 0, sizeof(b), b, NULL, NULL, NULL);
	err = clEnqueueNDRangeKernel(device->oclCommQueue, kernel, 1, 0, (const size_t*)c, 0, 0, NULL, NULL);
	err = clEnqueueReadBuffer(device->oclCommQueue, buffer3, CL_TRUE, 0, sizeof(c), c, NULL, NULL, NULL);
	if (err != CL_SUCCESS) {
		printf("error while reading buffer");
	}
	else {
		for (int i = 0; i < 5; i++) {
			printf("%d, ", c[i]);
		}
	}
	clReleaseKernel(kernel);
	clReleaseMemObject(buffer);
	return 0;
}*/
void runCL(oclC*);
int main() {
	cl_uint err = 0;
	cl_uint platforms = 0;
	cl_uint devices = 0;
	char* source = NULL;
	cl_platform_id* availablePlatforms = NULL;
	cl_device_id* availableDevices = NULL;
	oclC deviceconst;
	char platformName[150];
	getplatforms(&platforms, &availablePlatforms);
	for (uint32_t i = 0; i < 2; i++)
	{
		err = clGetPlatformInfo(availablePlatforms[i], CL_PLATFORM_NAME, 150, platformName, NULL);
		printf("platform %s",platformName);
	}
	getids(availablePlatforms[0], &devices, &availableDevices);
	source = readSource("image.cl");
	deviceconst.oclDevice = availableDevices[0];
	setupCL(&deviceconst, source);
	runCL(&deviceconst);
	return 0;
}
void runCL(oclC* device) {
	cl_uint err = 0;
	cl_kernel kernel;
	int width;
	int height;
	float* image;
	image = readImage("input.bmp", &width, &height);
	float *image_r;
	image_r = malloc(sizeof(float) * height * width);
	int filter[] = {
					-1,-2,-1,
					0,0,0,
					1,2,1};
	int filter_s = 9;
	cl_image_desc desc;
	desc.image_type = CL_MEM_OBJECT_IMAGE2D;
	desc.image_width = width;
	desc.image_height = height;
	desc.image_depth = 1;
	desc.image_row_pitch = 0;
	desc.image_slice_pitch = 0;
	desc.num_mip_levels = 0;
	desc.num_samples = 0;
	desc.buffer = NULL;
	cl_image_format format;
	format.image_channel_order = CL_R;
	format.image_channel_data_type = CL_FLOAT;
	//create the images
	cl_mem sourceImage = clCreateImage(device->oclContext, CL_MEM_READ_ONLY, &format, &desc, NULL, &err); 
	//printf("%d", err);
	//printf("%d\n", err);
	cl_mem result = clCreateImage(device->oclContext, CL_MEM_WRITE_ONLY, &format, &desc, NULL, &err);
	//printf("%d", err);
	cl_mem filter_buffer = clCreateBuffer(device->oclContext, CL_MEM_READ_ONLY, sizeof(filter), filter, &err);
	err = clEnqueueWriteBuffer(device->oclCommQueue, filter_buffer, CL_TRUE, 0, sizeof(filter), filter, NULL, NULL, NULL);
	//printf("%d", err);
	size_t origin[3] = { 0, 0, 0 };
	size_t region[3] = { width, height, 1};
	//read in the source image
	clEnqueueWriteImage(device->oclCommQueue, sourceImage, CL_TRUE, origin, region, 0, 0, image, 0, NULL, NULL);
	//create the sampler
	//cl_sampler_properties prop[7] = {CL_FALSE, CL_ADDRESS_CLAMP_TO_EDGE,CL_FILTER_NEAREST,0};
	//cl_sampler sampler = clCreateSamplerWithProperties(device->oclContext, prop, NULL);
	err = clBuildProgram(device->oclProgram, 1, &device->oclDevice, NULL, NULL, NULL);
	printf("%d", err);
	if (err == CL_BUILD_PROGRAM_FAILURE) {
		// Determine the size of the log
		size_t log_size;
		clGetProgramBuildInfo(device->oclProgram, device->oclDevice, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);

		// Allocate memory for the log
		char* log = (char*)malloc(log_size);

		// Get the log
		clGetProgramBuildInfo(device->oclProgram, device->oclDevice, CL_PROGRAM_BUILD_LOG, log_size, log, NULL);

		// Print the log
		printf("%s\n", log);
	}
	//create kernel
	kernel = clCreateKernel(device->oclProgram, "sobel", &err);
	//printf("%d", err);
	//set the args
	err = clSetKernelArg(kernel, 0, sizeof(sourceImage), (void*)&sourceImage);
	err = clSetKernelArg(kernel, 1, sizeof(result), (void*)&result);
	err = clSetKernelArg(kernel, 2, sizeof(int), (void*)&height);
	err = clSetKernelArg(kernel, 3, sizeof(int), (void*)&width);
	err = clSetKernelArg(kernel, 4, sizeof(filter_buffer), (void*)&filter_buffer);
	err = clSetKernelArg(kernel, 5, sizeof(int), (void*)&filter_s);
	//start the kernel
	int number = width * height;
	size_t global[] = { width,height };
	err = clEnqueueNDRangeKernel(device->oclCommQueue, kernel, 2, 0, global, 0, 0, NULL, NULL);
	//printf("%d", err);
	//read the image
	err = clEnqueueReadImage(device->oclCommQueue, result, CL_TRUE, origin, region, 0, 0, image_r, NULL,NULL,NULL);
	storeImage(image_r, "output.bmp", height, width, "input.bmp");
	clReleaseKernel(kernel);
	clReleaseMemObject(result);
	clReleaseMemObject(filter_buffer);
	clReleaseMemObject(sourceImage);
	return 0;

}