#ifndef __POLLER_H__
#define __POLLER_H__

#include <stdlib.h>
#include <poll.h>
#include <string.h>

#include "def.h"
#include "print.h"

typedef struct poller_event
{
	int magic;
    struct pollfd fd; 
    void *ptr;
}*poller_event_t;

typedef struct poller 
{
    int maxfds;
    struct poller_event *ev_list;

	pthread_mutex_t lock;
}*poller_t;

/// poller event
poller_event_t poller_event_create(void *ptr);
void poller_event_relase(poller_event_t event);
void poller_event_setfd(poller_event_t event, int fd);
void poller_event_setev(poller_event_t event, int ev);
void poller_event_clrev(poller_event_t event, int ev);

/// poller
int poller_create(int maxfds);
int poller_add(int pfd, poller_event_t event);
int poller_mod(int pfd, poller_event_t event);
int poller_del(int pfd, poller_event_t event);

int poller_wait(int pfd, struct poller_event *pv, int maxfds, int timeout);

#endif
