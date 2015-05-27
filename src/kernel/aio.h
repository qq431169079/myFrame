#ifndef __AIO_H__
#define __AIO_H__

#include "object.h"
#include "buffer.h"

/**
* @brief IO接口对象
* 目前支持
* 1、串口
* 2、TCP client、UDP client、unixdomain client
*/
typedef struct object_io
{
	struct object parent;	///<基类
	HMOD hmod;

	int fd;
	int isconnect;

	//配置信息(拷贝) 字符串型
	//串口：COM1 9600,8n1
	//TCP client：TCP_CLIENT 192.168.1.100:10001
	//UDP client：UDP_CLIENT 192.168.1.100:10001
	//unixdomain client: UNIX_DOMAIN /tmp/myframe.socket
	const char *settings;

	void *addr;	///<网络IPC的地址信息

	object_buf_t rbuf, wbuf;	///<读写缓存

	void (*_info)	(void);	///<接口版本信息
	int  (*_init)	(object_t parent, const char* settings);	///<初始化
	int  (*_connect)(object_t parent);	///<连接
	int  (*_state)	(object_t parent);	///<状态
	void (*_close)	(object_t parent);	///<关闭
	int  (*_recv)	(object_t parent);	///<读
	int  (*_send)	(object_t parent);	///<写
}*object_io_t;

#endif
