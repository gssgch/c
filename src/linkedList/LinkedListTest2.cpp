#include <stdio.h>
#include <malloc.h>
#include <conio.h>
/**
 *  ������ϰ  ����copy ��demo
 */
//����Ԫ���壬������ر���
struct student {
    int id;
    float score;
    struct student *next;
} *head,*pthis;

//�������ݴ�������
void input() {
    struct student *tmp;
    printf("\n\n������ѧ������Ϣ��ѧ��Ϊ0����:\n");
    do {
        printf("ID\t�ɼ�\n");
        if ((tmp=(struct student *)malloc(sizeof(struct student)))==NULL) {
            printf("\n����!��������������ڴ�!\n");
            exit(0);
        }
        scanf("%d\t%f",&tmp->id,&tmp->score);
        tmp->next=NULL;
        if (tmp->id!=0) {
            if (head==NULL) {
                head=tmp;
                pthis=head;
            } else {
                pthis->next=tmp;
                pthis=pthis->next;
            }
        }
    } while (tmp->id!=0);
    free(tmp);
}

//���������ҵ���һ��������������Ŀ���
void search(int id) {
    printf("\n\n��ѯ���\n");
    printf("ID\t�ɼ�\n");
    printf("-------------------------------\n");
    if (head==NULL) {
        printf("\n����!û������!\n");
        return;
    }
    pthis=head;
    while (pthis!=NULL) {
        if (pthis->id==id) {
            printf("%d\t%.2f\n",pthis->id,pthis->score);
            return;
        } else {
            pthis=pthis->next;
        }
    }
    printf("\nû���ҵ�!\n");
}

//�б���������е�������
void list() {
    printf("\n\n�����б�\n");
    printf("ID\t�ɼ�\n");
    printf("-------------------------------\n");
    if (head==NULL) {
        printf("����,û������!\n");
        return;
    }
    pthis=head;
    while (pthis!=NULL) {
        printf("%d\t%.2f\n",pthis->id,pthis->score);
        pthis=pthis->next;
    }
}

//��������
void insert() {
    int i,p;
    struct student *tmp;
    if (head==NULL) {
        printf("\n\n���ݲ����ڣ��޷�����!\n");
        return;
    }
    printf("\n����������:\n");
    scanf("%d",&p);
    if (p<0) {
        printf("���벻�Ϸ�!");
        return;
    }
    printf("\n\n������ѧ������Ϣ:\nID\t�ɼ�\n");
    if ((tmp=(struct student *)malloc(sizeof(struct student)))==NULL) {
        printf("\n����!��������������ڴ�!\n");
        exit(0);
    }
    scanf("%d\t%f",&tmp->id,&tmp->score);
    tmp->next=NULL;
    if (tmp->id!=0) {
        pthis=head;
        if (p==0) {
            tmp->next=head;
            head=tmp;
        } else {
            for (i=0; i<p-1; i++) {
                if (pthis->next->next==NULL) {
                    printf("\n�Ҳ�������㣬�����������̫��!\n");
                    return;
                }
                pthis=pthis->next;
            }
            tmp->next=pthis->next;
            pthis->next=tmp;
        }
    } else {
        printf("\n������Ч!\n");
        free(tmp);
    }
}

//׷������
void append() {
    struct student *tmp;
    printf("\n\n������ѧ������Ϣ:\nID\t�ɼ�\n");
    if ((tmp=(struct student *)malloc(sizeof(struct student)))==NULL) {
        printf("\n����!��������������ڴ�!\n");
        exit(0);
    }
    scanf("%d\t%f",&tmp->id,&tmp->score);
    tmp->next=NULL;
    if (tmp->id!=0) {
        if (head==NULL) {
            head=tmp;
        } else {
            pthis=head;
            while (pthis->next!=NULL) {
                pthis=pthis->next;
            }
            pthis->next=tmp;
        }
    } else {
        free(tmp);
        printf("\n������Ч!\n");
    }
}

//ɾ������
void del() {
    int p,i;
    struct student *tmp;
    if (head==NULL) {
        printf("\n\nû�����ݣ��޷�ɾ��!\n");
        return;
    }
    printf("\n\n������Ҫɾ���ļ�¼��:\n");
    scanf("%d",&p);
    if (p<0) {
        printf("\n���벻�Ϸ�!\n");
        return;
    }
    if (p==0) {
        pthis=head;
        head=pthis->next;
        free(pthis);
        pthis=head;
    } else {
        pthis=head;
        for (i=0; i<p-1; i++) {
            pthis=pthis->next;
            if (pthis->next==NULL) {
                printf("\n\nָ����¼�����ڣ��޷�ɾ��!\n");
                return;
            }
        }
        tmp=pthis->next;
        pthis->next=pthis->next->next;
        free(tmp);
    }
}

//����������
int main() {
    char command=0;
    int id=0;

//��ѭ��
    do {
        printf("\n\n\t�˵�2\n");
        printf("-------------------------------\n");
        printf("\ta,��������\n");
        printf("\tb,��ѯ��¼\n");
        printf("\tc,�����б�\n");
        printf("\td,׷�Ӽ�¼\n");
        printf("\te,�����¼\n");
        printf("\tf,ɾ����¼\n");
        printf("\tg,�˳�ϵͳ\n");
        printf("-------------------------------\n");
        printf("\t��ѡ��:");
        command=getch();

//�����
        switch (command) {
            case 'a':
                if (head==NULL) {
                    input();
                    break;
                } else {
                    printf("\n\n�����Ѿ����ڣ�\n");
                    break;
                }
            case 'b':
                printf("\n\nҪ��ѯ��ID:");
                scanf("%d",&id);
                search(id);
                break;
            case 'c':
                list();
                break;
            case 'd':
                append();
                break;
            case 'e':
                insert();
                break;
            case 'f':
                del();
                break;
        }
    } while (command!='g');
}