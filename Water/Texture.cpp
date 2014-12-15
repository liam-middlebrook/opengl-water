#include "Texture.h"

GLuint loadTexture(char* fileLoc)
{
	GLuint texture;

	FIBITMAP* bitmap = FreeImage_Load(
		FreeImage_GetFileType(fileLoc, 0),
		fileLoc);

	FIBITMAP* pImage;

	pImage = FreeImage_ConvertTo32Bits(bitmap);

	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, FreeImage_GetWidth(pImage), FreeImage_GetHeight(pImage),
		0, GL_BGRA, GL_UNSIGNED_BYTE, static_cast<void*>(FreeImage_GetBits(pImage)));

	FreeImage_Unload(bitmap);
	FreeImage_Unload(pImage);

	return texture;
}
