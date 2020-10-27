__constant sampler_t sampler = CLK_NORMALIZED_COORDS_FALSE | CLK_FILTER_LINEAR | CLK_ADDRESS_CLAMP;

__kernel void sobel(
__read_only image2d_t sourceImage,
__write_only image2d_t outputImage,
int rows,int cols,
__global int* filter,int filterWidth
){
	int col = get_global_id(0);
	int row = get_global_id(1);
	float4 sum = {0.0f,0.0f,0.0f,0.0f};
	int filterInd=0;
	int2 coords;
	for(int i = -1;i<= 1;i++){
		coords.y = row+i;
		for(int j= -1;j<= 1;j++){
			coords.x = col + j;
			float4 pxl;
			pxl = read_imagef(sourceImage,sampler,coords);
			sum.x += pxl.x * filter[filterInd++];
		}
	}
	if (row < rows && col < cols) {
		int2 coords2;
		coords2.x = col;
		coords2.y = row;
		write_imagef(outputImage, coords2, sum);
	}
}