/*
 * =====================================================================================
 *
 *       Filename:  def.h
 *
 *    Description:  def
 *
 *        Version:  1.0
 *        Created:  2014年09月19日 15时10分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lizhixian (R&D), lzx1442@163.com
 *        Company:  wanwei-tech
 *
 * =====================================================================================
 */
#ifndef __DEF_H__
#define __DEF_H__

#include <pthread.h>

#define TRUE		1
#define FALSE		0

#define REMOVE		-1
#define OFFLINE		0	
#define ONLINE		1	
#define CONNECTING	2


#define NOW time(NULL)

#define INIT_LOCK(lock) pthread_mutex_init(lock, NULL)
#define DEL_LOCK(lock) pthread_mutex_destroy(lock)
#define ENTER_LOCK(lock) pthread_mutex_lock(lock)
#define EXIT_LOCK(lock) pthread_mutex_unlock(lock)

#endif
