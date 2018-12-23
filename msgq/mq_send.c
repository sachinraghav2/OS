#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <errno.h>

int main()
{
	mqd_t cdacmq;
	struct mq_attr cdacattr;
	cdacattr.mq_flags = 0;
	cdacattr.mq_maxmsg = 3;
	cdacattr.mq_msgsize = 24;
	cdacattr.mq_curmsgs = 0;
	cdacmq = mq_open("/cmq", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR, &cdacattr);
	if(-1 == cdacmq)
	{
		perror("error ");
		exit(1);
	}
	mq_send(cdacmq, "Hello\n",  6, 0);
	mq_close(cdacmq);
	return 0;
}
