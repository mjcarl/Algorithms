#include<iostream>
#include<assert.h>
#include<string>

void* memmove(void *dest,const void* src,size_t count)  //ʵ���ڴ������ݵĸ��ơ���memcpy��ͬ������Ҫע���ڴ��Ƿ�����ص��������
{
    assert((dest != NULL) && (src != NULL));

    unsigned char *pdst = (unsigned char *)dest;
    const unsigned char *psrc = (const unsigned char *)src;

    assert(!(psrc<=pdst && pdst<psrc+count));   //��ֹ�ڴ渲�ǣ�Ŀ�ĵ�ַ������Դ��ַ��ǰ�档���ָ���ʱ���ԴӺ���ǰ������

    while(count--)
    {
        *pdst = *psrc;
        pdst++;
        psrc++;
    }
    return pdst;
}
