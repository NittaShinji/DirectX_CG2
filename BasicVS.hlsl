#include"Basic.hlsli"

//P04_01_P25
VSOutput main(float4 pos : POSITION, float2 uv : TEXCOORD)
{
	VSOutput output; //�s�N�Z���V�F�[�_�[�ɓn���l
	//output.svpos = pos;
	 
	//�V�X�e���p���_���W
	output.svpos = mul(mat, pos);//���W��3D�ϊ��s�����Z
	//UV�l
	output.uv = uv;
	return output;
}

//float4 main( float4 pos : POSITION ) : SV_POSITION
//{
//	return pos + float4( 0,0,1,1);
//}