#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
void main()
{
    int choice;
    char option;
    void display(int []);
    void multiplayer();
    void playerVsComputer();
    while(1)
    {
        printf("\nYou have 2 Choice\n1...Player 1 VS Player 2\n2...Player VS Computer\nEnter your choice ( 1 or 2 ) : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: multiplayer();
                    break;
            case 2: playerVsComputer();
                    break;
            default: printf("\n\nInvalid Input");
                     break;
        }
        attemp : printf("\n\nAre you want to play the game again\nIf YES then enter Y otherwise enter N\nOption = ");
        scanf("%s",&option);
        if(option=='N' || option=='n')
        {
            break;
        }
        else if (option=='y' || option=='Y')
        {
            continue;
        }
        else
        {
            printf("\nYou have entered the wrong value\nPlease enter the correct value ( Y or N )");
            goto attemp;
        }        
    }    
}

void display(int game[9])
{
    int i;
    for(i=0;i<9;i++)
    {
        printf("%d\t",game[i]);
        if(i==2 || i==5)
        {
            printf("\n");
        }    
    }
    printf("\n");
}

void multiplayer()
{
    int i,j=0,k,x,flag=0,size[2],pos[9];
    int game[9]={0,0,0,0,0,0,0,0,0};
    printf("Hello !!!\nWELCOME in the GAME\n\nPlayer_1 VS Player_2\n");
    printf("Player_1 have 1 and Player_2 have -1\n");
    printf("First is Player_1 Chance and then Player_2 Chance and then repeat this process for 9 Steps\n");
    for(i=1;i<10;i++)
    {
        if(i==1 || i==3 || i==5 || i==7 || i==9)  //This condition ( If part ) is used for Player_1 Chance
        {
            printf("\nPlayer_1 Chance");
            printf("\n\nEnter your position from 1 - 9 in which your choice ( 1 ) is filled\nPosition = ");
            scanf("%d",&pos[j]);
            if(pos[j]>9)
            {
                printf("\nPlease enter the position in the range of 1 - 9");
                i--;
            }
            else
            {
                for(k=j;k>0;k--)  //This loop is used to check that the position is free or not
                {
                    x=j;
                    flag=0;
                    if(pos[x]==pos[k-1])
                    {
                        printf("This position is already filled...\n\nPlease reselect or change your position");
                        i--;
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    game[pos[j]-1]=1;  //Entry in game
                    j++; 
                    printf("After %d step the game is :\n",i);
                    display(game);
                }
                if(i==5 || i==7 || i==9)  //Break or End the Game ( Player_1 Won the GAME )
                {
                    if((game[0]+game[1]+game[2]==3) || (game[3]+game[4]+game[5]==3) || (game[6]+game[7]+game[8]==3) || (game[0]+game[3]+game[6]==3) || (game[1]+game[4]+game[7]==3) || (game[2]+game[5]+game[8]==3) || (game[0]+game[4]+game[8]==3) || (game[2]+game[4]+game[6]==3))
                    {
                        printf("\n\nCongratulations !!!\nPlayer_1 Won...");
                        break;
                    }
                }  
            }
        }    
        else  //Else part is for Player_2 Chance
        {
            printf("\nPlayer_2 Chance");
            printf("\n\nEnter your position from 1 - 9 in which your choice ( 1 ) is filled\nPosition = ");
            scanf("%d",&pos[j]);
            if(pos[j]>9)
            {
                printf("\nPlease enter the position in the range of 1 - 9");
                i--;
            }
            else
            {
                for(k=j;k>0;k--)  //This loop is used to check that the position is free or not
                {
                    x=j;
                    flag=0;
                    if(pos[x]==pos[k-1])
                    {
                        printf("This position is already filled...\n\nPlease reselect or change your position");
                        i--;
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    game[pos[j]-1]=-1;  //Entry in game
                    j++; 
                    printf("After %d step the game is :\n",i);
                    display(game);
                }       
            }
            if(i==6 || i==8)  //Break or End the Game ( Computer Won the GAME )
            {
                if((game[0]+game[1]+game[2]==-3) || (game[3]+game[4]+game[5]==-3) || (game[6]+game[7]+game[8]==-3) || (game[0]+game[3]+game[6]==-3) || (game[1]+game[4]+game[7]==-3) || (game[2]+game[5]+game[8]==-3) || (game[0]+game[4]+game[8]==-3) || (game[2]+game[4]+game[6]==-3))
                {
                    printf("\n\nCongratulations !!!\nPlayer_2 Won...");
                    break;
                }
            }
        }    
    }
    if(i==10)
    {
        printf("\n\nGAME OVER !!!\nRETRY TO WIN THE GAME...");
    }
}    

void playerVsComputer()
{
    int i,j=0,k,x,s,p,rand_pos,temp,flag=0,size[2],pos[9];
    int game[9]={0,0,0,0,0,0,0,0,0};
    printf("Hello !!!\nWELCOME in the GAME\n");
    printf("You have 1 and Computer have -1\n");
    printf("First is Your Chance and then Computer's Chance and then repeat this for 9 steps\n");
    for(i=1;i<10;i++)
    {
        if(i==1 || i==3 || i==5 || i==7 || i==9)  //This condition ( If part ) is used for user's chance
        {
            printf("\n\nEnter your position from 1 - 9 in which your choice ( 1 ) is filled\nPosition = ");
            scanf("%d",&pos[j]);
            if(pos[j]>9)
            {
                printf("\nPlease enter the position in the range of 1 - 9");
                i--;
            }
            else
            {
                for(k=j;k>0;k--)  //This loop is used to check that the position is free or not
                {
                    x=j;
                    flag=0;
                    if(pos[x]==pos[k-1])
                    {
                        printf("This position is already filled...\n\nPlease reselect or change your position");
                        i--;
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    game[pos[j]-1]=1;  //Entry in game
                    j++; 
                    printf("After %d step the game is :\n",i);
                    display(game);
                }
                if(flag==0 || i==5 || i==7 || i==9)  //Break or End the Game ( User Won the GAME )
                {
                    if((game[0]+game[1]+game[2]==3) || (game[3]+game[4]+game[5]==3) || (game[6]+game[7]+game[8]==3) || (game[0]+game[3]+game[6]==3) || (game[1]+game[4]+game[7]==3) || (game[2]+game[5]+game[8]==3) || (game[0]+game[4]+game[8]==3) || (game[2]+game[4]+game[6]==3))
                    {
                        printf("\n\nCongratulations !!!\nYou Won...");
                        break;
                    }
                }
            }      
        }
        else  //Else part is for Computer's Chance
        {
            if(i==2)  //First chance of computer 
            {
                srand(time(0));
                rand_pos=rand()%9;
                for(k=j-1;k>=0;k--)  //This loop is used to check that the position is free or not
                {
                    flag=0;
                    if(pos[k]==rand_pos)
                    {
                        temp=0;
                        i--;
                        flag=1;
                        temp = temp +1;
                        if (temp==1)
                        {
                            printf("This position is already filled...\nPlease reselect or change your position");
                        } 
                        break;
                    }
                }
                if(flag==0)
                {
                    pos[j]=rand_pos;
                    game[pos[j]-1]=-1;
                    j++;
                    printf("\n\nAfter %d step the game is :\n",i);
                    display(game);
                }   
            }
            else
            {
                if(game[0]+game[1]+game[2]==-2)  //For 1 Row
                {
                    s=0;
                    for(p=j-1;p>=0;p--)
                    {
                        if(pos[p]==1 || pos[p]==2 || pos[p]==3)  //Position is 1-9
                        {
                            size[s]=pos[p];
                            s++;
                        }
                    }
                    if(size[0]==1 || size[1]==1)
                    {
                        if(size[0]==2 || size[1]==2)
                        {
                            pos[j]=3;
                            game[2]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                        else
                        {
                            pos[j]=2;
                            game[1]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                    } 
                    else
                    {
                        pos[j]=1;
                        game[0]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }   
                }
                else if(game[3]+game[4]+game[5]==-2)  // For 2 Row
                {
                    s=0;
                    for(p=j-1;p>=0;p--)
                    {
                        if(pos[p]==4 || pos[p]==5 || pos[p]==6)  //Position is 1-9
                        {
                            size[s]=pos[p];
                            s++;
                        }
                    }
                    if(size[0]==4 || size[1]==4)
                    {
                        if(size[0]==5 || size[1]==5)
                        {
                            pos[j]=6;
                            game[5]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                        else
                        {
                            pos[j]=5;
                            game[4]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                    } 
                    else
                    {
                        pos[j]=4;
                        game[3]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }
                }
                else if(game[6]+game[7]+game[8]==-2)  // For 3 Row
                {
                    s=0;
                    for(p=j-1;p>=0;p--)
                    {
                        if(pos[p]==7 || pos[p]==8 || pos[p]==9)  //Position is 1-9
                        {
                            size[s]=pos[p];
                            s++;
                        }
                    }
                    if(size[0]==7 || size[1]==7)
                    {
                        if(size[0]==8 || size[1]==8)
                        {
                            pos[j]=9;
                            game[8]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                        else
                        {
                            pos[j]=8;
                            game[7]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                    } 
                    else
                    {
                       pos[j]=7;
                        game[6]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }
               }
                else if(game[0]+game[3]+game[6]==-2)  // For 1 Column
                {
                    s=0;
                    for(p=j-1;p>=0;p--)
                    {
                        if(pos[p]==1 || pos[p]==4 || pos[p]==7)  //Position is 1-9
                        {
                            size[s]=pos[p];
                            s++;
                        }
                    }
                    if(size[0]==1 || size[1]==1)
                    {
                        if(size[0]==4 || size[1]==4)
                        {
                            pos[j]=7;
                            game[6]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                        else
                        {
                            pos[j]=4;
                            game[3]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                    } 
                    else
                    {
                        pos[j]=1;
                        game[0]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }
                }
                else if(game[1]+game[4]+game[7]==-2)  // For 2 Column
                {
                    s=0;
                    for(p=j-1;p>=0;p--)
                    {
                        if(pos[p]==2 || pos[p]==5 || pos[p]==8)  //Position is 1-9
                        {
                            size[s]=pos[p];
                            s++;
                        }
                    }
                    if(size[0]==2 || size[1]==2)
                    {
                        if(size[0]==5 || size[1]==5)
                        {
                            pos[j]=8;
                            game[7]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                        else
                        {
                            pos[j]=5;
                            game[4]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                    } 
                    else
                    {
                        pos[j]=2;
                        game[1]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }
                }
                else if(game[2]+game[5]+game[8]==-2)  //For 3 Column
                {
                    s=0;
                    for(p=j-1;p>=0;p--)
                    {
                        if(pos[p]==3 || pos[p]==6 || pos[p]==9)  //Position is 1-9
                        {
                            size[s]=pos[p];
                            s++; 
                        }
                    }
                    if(size[0]==3 || size[1]==3)
                    {
                        if(size[0]==6 || size[1]==6)
                        {
                            pos[j]=9;
                            game[8]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                        else
                        {
                            pos[j]=6;
                            game[5]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                    } 
                    else
                    {
                        pos[j]=3;
                        game[2]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }
                }
                else if(game[0]+game[4]+game[8]==-2)  // For 1 Diagonal ( Principal Diagonal )
                {
                    s=0;
                    for(p=j-1;p>=0;p--)
                    {
                        if(pos[p]==1 || pos[p]==5 || pos[p]==9)  //Position is 1-9
                        {
                            size[s]=pos[p];
                            s++;
                        }
                    }
                    if(size[0]==1 || size[1]==1)
                    {
                        if(size[0]==5 || size[1]==5)
                        {
                            pos[j]=9;
                            game[8]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                        else
                        {
                            pos[j]=5;
                            game[4]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                    } 
                    else
                    {
                        pos[j]=1;
                        game[0]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }
                } 
                else if(game[2]+game[4]+game[6]==-2)  // For 2 Diagonal 
                {
                    s=0;
                    for(p=j-1;p>=0;p--)
                    {
                        if(pos[p]==3 || pos[p]==5 || pos[p]==7)  //Position is 1-9
                        {
                            size[s]=pos[p];
                            s++;
                        }
                    }
                    if(size[0]==3 || size[1]==3)
                    {
                        if(size[0]==5 || size[1]==5)
                        {
                            pos[j]=7;
                            game[6]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                        else
                        {
                            pos[j]=5;
                            game[4]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                    } 
                    else
                    {
                        pos[j]=3;
                        game[2]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }
                }
                else if(game[0]+game[1]+game[2]==2)  //For 1 Row
                {
                    s=0;
                    for(p=j-1;p>=0;p--)
                    {
                        if(pos[p]==1 || pos[p]==2 || pos[p]==3)  //Position is 1-9
                        {
                            size[s]=pos[p];
                            s++;
                        }
                    }
                    if(size[0]==1 || size[1]==1)
                    {
                        if(size[0]==2 || size[1]==2)
                        {
                            pos[j]=3;
                            game[2]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                        else
                        {
                            pos[j]=2;
                            game[1]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                    } 
                    else
                    {
                        pos[j]=1;
                        game[0]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }   
                }
                else if(game[3]+game[4]+game[5]==2)  // For 2 Row
                {
                    s=0;
                    for(p=j-1;p>=0;p--)
                    {
                        if(pos[p]==4 || pos[p]==5 || pos[p]==6)  //Position is 1-9
                        {
                            size[s]=pos[p];
                            s++;
                        }
                    }
                    if(size[0]==4 || size[1]==4)
                    {
                        if(size[0]==5 || size[1]==5)
                        {
                            pos[j]=6;
                            game[5]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                        else
                        {
                            pos[j]=5;
                            game[4]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                    } 
                    else
                    {
                        pos[j]=4;
                        game[3]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }
                }
                else if(game[6]+game[7]+game[8]==2)  // For 3 Row
                {
                    s=0;
                    for(p=j-1;p>=0;p--)
                    {
                        if(pos[p]==7 || pos[p]==8 || pos[p]==9)  //Position is 1-9
                        {
                            size[s]=pos[p];
                            s++;
                        }
                    }
                    if(size[0]==7 || size[1]==7)
                    {
                        if(size[0]==8 || size[1]==8)
                        {
                            pos[j]=9;
                            game[8]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                        else
                        {
                            pos[j]=8;
                            game[7]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                    } 
                    else
                    {
                        pos[j]=7;
                        game[6]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }
                }
                else if(game[0]+game[3]+game[6]==2)  // For 1 Column
                {
                    s=0;
                    for(p=j-1;p>=0;p--)
                    {
                        if(pos[p]==1 || pos[p]==4 || pos[p]==7)  //Position is 1-9
                        {
                            size[s]=pos[p];
                            s++;
                        }
                    }
                    if(size[0]==1 || size[1]==1)
                    {
                        if(size[0]==4 || size[1]==4)
                        {
                            pos[j]=7;
                            game[6]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                        else
                        {
                            pos[j]=4;
                            game[3]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                    } 
                    else
                    {
                        pos[j]=1;
                        game[0]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }
                }
                else if(game[1]+game[4]+game[7]==2)  // For 2 Column
                {
                    s=0;
                    for(p=j-1;p>=0;p--)
                    {
                        if(pos[p]==2 || pos[p]==5 || pos[p]==8)  //Position is 1-9
                        {
                            size[s]=pos[p];
                            s++;
                        }
                    }
                    if(size[0]==2 || size[1]==2)
                    {
                        if(size[0]==5 || size[1]==5)
                        {
                            pos[j]=8;
                            game[7]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                        else
                        {
                            pos[j]=5;
                            game[4]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                    } 
                    else
                    {
                        pos[j]=2;
                        game[1]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }
                }
                else if(game[2]+game[5]+game[8]==2)  //For 3 Column
                {
                    s=0;
                    for(p=j-1;p>=0;p--)
                    {
                        if(pos[p]==3 || pos[p]==6 || pos[p]==9)  //Position is 1-9
                        {
                            size[s]=pos[p];
                            s++;
                        }
                    }
                    if(size[0]==3 || size[1]==3)
                    {
                        if(size[0]==6 || size[1]==6)
                        {
                            pos[j]=9;
                            game[8]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                        else
                        {
                            pos[j]=6;
                            game[5]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                    } 
                    else
                    {
                        pos[j]=3;
                        game[2]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }
                }
                else if(game[0]+game[4]+game[8]==2)  // For 1 Diagonal ( Principal Diagonal )
                {
                    s=0;
                    for(p=j-1;p>=0;p--)
                    {
                        if(pos[p]==1 || pos[p]==5 || pos[p]==9)  //Position is 1-9
                        {
                            size[s]=pos[p];
                            s++;
                        }
                    }
                    if(size[0]==1 || size[1]==1)
                    {
                        if(size[0]==5 || size[1]==5)
                        {
                            pos[j]=9;
                            game[8]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                        else
                        {
                            pos[j]=5;
                            game[4]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                    } 
                    else
                    {
                        pos[j]=1;
                        game[0]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }
                } 
                else if(game[2]+game[4]+game[6]==2)  // For 2 Diagonal 
                {
                    s=0;
                    for(p=j-1;p>=0;p--)
                    {
                        if(pos[p]==3 || pos[p]==5 || pos[p]==7)  //Position is 1-9
                        {
                            size[s]=pos[p];
                            s++;
                        }
                    }
                    if(size[0]==3 || size[1]==3)
                    {
                        if(size[0]==5 || size[1]==5)
                        {
                            pos[j]=7;
                            game[6]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                        else
                        {
                            pos[j]=5;
                            game[4]=-1;
                            j++;
                            printf("\n\nAfter %d step the game is :\n",i);
                            display(game);
                        }
                    } 
                    else
                    {
                        pos[j]=3;
                        game[2]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }
                }
                else
                {
                    srand(time(0));
                    rand_pos=rand()%9;
                    for(k=j-1;k>=0;k--)  //This loop is used to check that the position is free or not
                    {
                        flag=0;
                        if(pos[k]==rand_pos)
                        {
                            temp=0;
                            i--;
                            flag=1;
                            temp = temp +1;
                            if (temp==1)
                            {
                                printf("This position is already filled...\nPlease reselect or change your position");
                            } 
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        pos[j]=rand_pos;
                        game[pos[j]-1]=-1;
                        j++;
                        printf("\n\nAfter %d step the game is :\n",i);
                        display(game);
                    }
                }
                if(flag==0 || i==6 || i==8)  //Break or End the Game ( Computer Won the GAME )
                {
                    if((game[0]+game[1]+game[2]==-3) || (game[3]+game[4]+game[5]==-3) || (game[6]+game[7]+game[8]==-3) || (game[0]+game[3]+game[6]==-3) || (game[1]+game[4]+game[7]==-3) || (game[2]+game[5]+game[8]==-3) || (game[0]+game[4]+game[8]==-3) || (game[2]+game[4]+game[6]==-3))
                    {
                        printf("\n\nGame Over !!!\nComputer Won...");
                        break;
                    }
                }
            }
        }    
    }
    if(i==10)
    {
        printf("\n\nGAME OVER !!!\nRETRY TO WIN THE GAME...");
    }
}