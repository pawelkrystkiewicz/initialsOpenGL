/*#include "stdafx.h"
#include <wincodec.h>
#pragma commment(lib, "windowscodecs.lib")
#define GL_GENERATE_MIPMAP 0x8191

GLuint uploadTexture(wchar_t *filename)
{
	IWICImagingFactory *factory;
	IWICBitmapDecoder *decoder;
	IWICBitmapFrameDecode *frame;
	IWICFormatConverter *bmp;
	unsigned int width, height;
	HRESULT init = CoInitialize(NULL);
	CoCreateInstance(CLSID_WICImagingFactory1, NULL, CLSCTX_INPROC_SERVER, IID_IWICImagingFactory, (LPVOID*)&factory);
	factory->CreateDecoderFromFilename(filename, NULL, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &decoder);
	decoder->GetFrame(0, &frame);
	factory->CreateFormatConverter(&bmp);
	bmp->Initialize(frame, GUID_WICPixelFormat32bppBGRA, WICBitmapDitherTypeNone, NULL, 0, WICBitmapPaletteTypeCustom);
	bmp->GetSize(&width, &height);

	size_t row_size = 4 * width;
	size_t data_size = row_size * height;

	unsigned char *data = (unsigned char*)malloc(data_size);
	unsigned char *scanline = data + data_size;
	for (unsigned int i = 0; i < height; i++)
	{	
		scanline -= row_size;
		WICRect rect = { 0, i, width, 1 };
		bmp->CopyPixels(&rect, row_size, row_size, scanline);
	}
	bmp->Release();
	frame->Release();
	decoder->Release();
	factory->Release();
	
	if (SUCCEEDED(init)) CoUninitialize();

	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, data);
	free(data);
	return texture;
}
*/