#ifndef COMPRESS_H
#define COMPRESS_H
//typedef char **HuffmanCode;

//�ļ�ͷ
struct HEAD
{
	char type[4];
	int length;
	int weight[256];
};

//ʵ���ļ�ѹ��
int Compress(const char *pFilename);

//��ȡԴ�ļ��ͳ�ʼ��ͷ�ļ�����Ϣ
int InitHead(const char * pFilname, HEAD & sHead);

//����Huffman���� ʵ��ѹ������
int Encode(const char *, char**, char *, const int);
//int Encode(const char *pFilname, const HuffmanCode pHC, char *pBuffer, const int nSize);

//���������ַ���ת�����ֽ�
char Str2byte(const char * pBinStr);

//����ѹ���ļ�
int WriteFile(const char * pFilename, const HEAD sHead, const char * pBuffer, const int nSize);

#endif