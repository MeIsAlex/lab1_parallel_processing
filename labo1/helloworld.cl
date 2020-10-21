/*
__kernel void HelloWorld(__global uint *idOutput)
{
	uint id = get_global_id(0);

	idOutput[id] = id;
}
__kernel void HelloWorld1(__global char* b,__global char* a){
	uint tid = get_global_id(0);
	b[tid]=a[tid];
}
__kernel void lab2_oef1(__global int *a,__global int *b,__global int *c){
	int id = get_global_id(0);
	c[id] = a[id] + b[id];
}
__kernel void lab2_oef2(__global int *a,__global int *b,__global int *c,__global int w){
	int x = get_global_id(0);
	int y = get_global_id(1);
	int sum = 0;
	for(int i=0;i<w;i++){
		sum+= a[i][y] * b[x][i];
	}
	c[x][y]=sum;
}
*/
__kernel void lab2_oef3(__global int *a,__global int *b,__global int *c){
	int id = get_global_id(0);
	int sum = a[id] + b[id];
	c[id]=sum/2;
}
