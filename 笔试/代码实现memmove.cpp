#include<iostream>
#include<assert.h>
#include<string>

void* memmove(void *dest,const void* src,size_t count)  //实现内存中内容的复制。与memcpy不同的是需要注意内存是否存在重叠的情况。
{
    assert((dest != NULL) && (src != NULL));

    unsigned char *pdst = (unsigned char *)dest;
    const unsigned char *psrc = (const unsigned char *)src;

    assert(!(psrc<=pdst && pdst<psrc+count));   //防止内存覆盖，目的地址不能在源地址的前面。出现覆盖时可以从后向前拷贝！

    while(count--)
    {
        *pdst = *psrc;
        pdst++;
        psrc++;
    }
    return pdst;
}
