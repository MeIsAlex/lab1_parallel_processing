#define SOFTENING 1e-9f;

__kernel void nbody(__global float4* pos,__global float4* vel, __global float4* posRes, __global float4* velRes,float dt,int n)
{
	float Fx = 0.0f; float Fy = 0.0f; float Fz = 0.0f;
	int index = get_global_id(0);
	float4 a = pos[index];
    float4 b = vel[index];
    #pragma unroll
    for (int j = 0; j < n; j++) {
        float dx = pos[j].x - a.x;
        float dy = pos[j].y - a.y;
        float dz = pos[j].z - a.z;
        float distSqr = dx * dx + dy * dy + dz * dz + SOFTENING;
        float invDist = 1.0f / sqrt(distSqr);
        float invDist3 = invDist * invDist * invDist;

        Fx += dx * invDist3; Fy += dy * invDist3; Fz += dz * invDist3;
    }
    b.x += dt * Fx; b.y += dt * Fy; b.z += dt * Fz;
    //new pos
    a.x += b.x * dt;
    a.y += b.y * dt;
    a.z += b.z * dt;
    //set result
    posRes[index] = a;
    velRes[index] = b;
}