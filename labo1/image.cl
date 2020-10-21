__kernel void sobel(
image2d_t sourceImage,
image2d_t outputImage,
int row,int col,
float* filter,int filterWidth
){
	__constant sampler_t sampler = CLK_NORMALIZED_COORDS_FALSE | CLK_FILTER_LINEAR | CLK_ADDRESS_CLAMP;
	int col = get_global_id(0);
	int row get_global_id(1);
	int halfWidth = (int)(filterWidth/2);
	float4 sum = {0.0f,0.0f,0.0f,0.0f};
	int filterInd=0;
	int2 coords;
	for(int i = -halfWidth;i<=halfWidth;i++){
		coords.y = row+i;
		for(int j= -halfWidth;j<=halfwidth;j++){
			coords.x = column + j;
			float4 pxl;
			pxl = read_imagef(sourceImage,sampler,coords);
			sum.x += pixel.x *filter[filterInd++];
		}
	}
}