#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	mqd_t cdacmq;
	char buff[24];
	unsigned int prio;
	struct mq_attr cdacattr;
	cdacattr.mq_flags = 0;
	cdacattr.mq_maxmsg = 3;
	cdacattr.mq_msgsize = 24;
	cdacattr.mq_curmsgs = 0;
	cdacmq = mq_open("/cmq", O_RDONLY, S_IRUSR | S_IWUSR, &cdacattr);
	mq_receive(cdacmq, buff,  24, &prio);
	printf("%s\n",buff);
	mq_close(cdacmq);
	return 0;
}
