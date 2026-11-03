#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>

int main(void)
{
	int id;		//共有メモリID
	double *data;

	//共有メモリ作成
	id = shmget(IPC_PRIVATE, sizeof(double), IPC_CREAT|0666);

	//メモリ共有
	data = (double *)shmat(id,NULL,0);

	while(1)
	{
		printf("共有メモリ(id=%d)のデータは%f\n",id,*data);

		//負のデータが書き込まれたら終了
		if(*data <0)
			break;

		sleep(1);
	}

	//共有メモリ削除
	shmctl(id,IPC_RMID,0);

	return 0;
}
