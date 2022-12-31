
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct node{
	char data[40];
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
struct node *current_node=NULL;
char temp[40];
int main(){
	int ch;
	while(ch!=9){
		
		printf("\t====================================================================================\n");
		printf("\t\t\t\t--------Music Player!!!--------\n");
		printf("\t====================================================================================\n");
		printf("\n\t1.Add Music\t\t\t");
		printf("2.Remove Music\t\t\t");
		printf("3.Show Playlist\t\t\t\n");
		printf("\t====================================================================================\n");
		printf("\t4.Play Next Music\t\t");
		printf("5.Play Previous Music\t\t");
		printf("6.Play First File\n");
		printf("\t====================================================================================\n");
		printf("\t7.Play Last File");
		printf("\t\t8.Play Specific File");
		printf("\t\t9.Exit\n");
		printf("\t====================================================================================\n");
		printf("\t10.Change color theme.");
		printf("\n\tEnter your Choice\t:");
		scanf("%d",&ch);
		switch(ch){
			case 1:{
			
				insert_();
				break;
			}
			case 2:{
			
				delete_element();
				break;
			}
			case 3:{
			
				show();
				break;
			}
			case 4:{
			
				next_node();
				break;
			}
			case 5:{
			
				previous_node();
				break;
			}
			case 6:{
			
				first_node();
				break;
			}
			case 7:{
				
				last_node();
				break;
			}
			case 8:{
				specific_data();
				break;
			}
			case 9:{
				printf("\tPlayer Closed!!!");
				exit(0);
		
			}
			case 10:{
				change_color();
				break;
			}
			default:{
				printf("\tWrong Choice!! Enter the Choice from the Given OPTION\n");
				break;
			}
		}
	}
return 0;	
}
int insert_(){
	getchar();
	printf("\tEnter the music name: ");
	gets(temp);
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	strcpy(new_node->data,temp);
	if(head==NULL){
		new_node->next=new_node->prev=new_node;
		current_node=head=new_node;
		printf("Music Added!!\n");
	}
	struct node *last=head->prev;
	new_node->prev=last;
	last->next=new_node;
	new_node->next=head;
	head->prev=new_node;
	system("cls");
	printf("\t\tMusic Added!!\n");
return 0;
}
int delete_element(){
	if(head==NULL){
		system("cls");
		printf("\tNo Music To Delete");
	}
	else{
		getchar();
		printf("\tEnter the music name: ");
		gets(temp);
		struct node *ptr=head;
		do{
			if(ptr->next==ptr&&strcmp(ptr->data,temp)==0){
				system("cls");
				printf("\tFile deleted ! Playlist is empty!\n");
				head=NULL;
				free(ptr);
				return;
			}
			else if(strcmp(ptr->data,temp)==0){
				struct node *prev=ptr->prev;
				struct node *next=ptr->next;
				prev->next=next;
				next->prev=prev;
				//head=next;
				free(ptr);
				system("cls");
				printf("\tMusic Deleted\n");
				return;
			}
			ptr=ptr->next;
		}while(ptr!=head);
		system("cls");
		printf("\tNo music file named %s\n",temp);
	}
return 0;
}
int show(){
	if(head==NULL){
		system("cls");
		printf("\tPlaylist is empty!!\n");
	}
	else{
		struct node *ptr=head;
		int i=0;
		system("cls");
		printf("\n\t-----Available music-----\n");
		do{
			printf("\t%d. %s.\n",++i,ptr->data);
			ptr=ptr->next;
		}while(ptr!=head);
	}
return 0;
}
int next_node(){
	if(current_node==NULL){
		system("cls");
		printf("\tNo song in playlist!\n");
		
	}
	else{
		current_node=current_node->next;
		system("cls");
		printf("\tPlaying Music :%s\n",current_node->data);
	}
return 0;
}
int previous_node(){
	if(current_node==NULL){
		system("cls");
		printf("\tNo song in playlist!\n");
		
	}
	else{
		current_node=current_node->prev;
		system("cls");
		printf("\tPlaying Music :%s\n",current_node->data);
	}
return 0;
}
int last_node(){
	if(current_node==NULL){
		system("cls");
		printf("\tNo song in playlist!\n");
		
	}
	else{
		current_node=head->prev;
		system("cls");
		printf("\tPlaying Music :%s\n",current_node->data);
	}
return 0;
}
int first_node(){
	if(current_node==NULL){
		system("cls");
		printf("\tNo song in playlist!\n");
		
	}
	else{
		current_node=head;
		system("cls");
		printf("\tPlaying Music :%s\n",current_node->data);
	}
return 0;
}
int specific_data(){
	if(head==NULL){
		system("cls");
		printf("\tNo Music in Playlist!!\n");
	}
	else{
		int flag=0;
		char temp[10];
		getchar();
		printf("\tEnter the music name: ");
		gets(temp);
		struct node *ptr=head;
		do{
			if(strcmp(ptr->data,temp)==0){
				system("cls");
				printf("\t playing :%s\n",temp);
				flag=1;
				return;
			}
			ptr=ptr->next;
		}while(ptr!=head);
		system("cls");
		printf("\t%s\n",flag==0?"There is no music ":"");
return 0;
}
}
int change_color(){
	int color;
	printf("\tEnter the color theme for your music player\n");
	printf("\t1.Green \t2.Aqua\t\t3.Red\n\t4.Purple\t5.Yellow\t6.White\n");
	scanf("%d",&color);
	switch(color){
		case 1:{
			system("COLOR 0A");
			system("cls");
			break;
		}
		case 2:{
			system("COLOR 0B");
			system("cls");
			break;
		}
		case 3:{
			system("COLOR 0C");
			system("cls");
			break;
		}
		case 4:{
			system("COLOR 0D");
			system("cls");
			break;
		}
		case 5:{
			system("COLOR 0E");
			system("cls");
			break;
		}
		case 6:{
			system("COLOR 0F");
			system("cls");
			break;
		}
	}
}

