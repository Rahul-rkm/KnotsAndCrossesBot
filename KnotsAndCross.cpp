#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char board[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
char cp='a',p='p';
void drawBoard()
{
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",board[7],board[8],board[9]);
    printf("   |   |   \n");
    printf("---+---+---\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",board[4],board[5],board[6]);
    printf("   |   |   \n");
    printf("---+---+---\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",board[1],board[2],board[3]);
    printf("   |   |   \n");

}

int have_won(char c)
{
    int x=0;
    for(int i=1;i<=3;i++)
    {
        if(board[i]==c)
            x++;
    }
    if(x==3)
        return 1;
    x=0;
    for(int i=4;i<=6;i++)
    {
        if(board[i]==c)
            x++;
    }
    if(x==3)
        return 1;
    x=0;
    for(int i=7;i<=9;i++)
    {
        if(board[i]==c)
            x++;
    }
    if(x==3)
        return 1;
    x=0;
    for(int i=1;i<=7;i+=3)
    {
        if(board[i]==c)
            x++;
    }
    if(x==3)
        return 1;
    x=0;
    for(int i=2;i<=8;i+=3)
    {
        if(board[i]==c)
            x++;
    }
    if(x==3)
        return 1;
    x=0;
    for(int i=3;i<=9;i+=3)
    {
        if(board[i]==c)
            x++;
    }
    if(x==3)
        return 1;
    x=0;
    for(int i=1;i<=9;i+=4)
    {
        if(board[i]==c)
            x++;
    }
    if(x==3)
        return 1;
    x=0;
    for(int i=3;i<=7;i+=2)
    {
        if(board[i]==c)
            x++;
    }
    if(x==3)
        return 1;
    else
        return 0;
}

void cpuMove()
{
    int k=0;
    for(int i=1;i<=9;i++)   //tries to find winning move
    {
        if(board[i]!=' ')
            continue;
        board[i] = cp;
        if(have_won(cp))       //checks the winning move
        {
            board[i] = cp;
            return;
        }
        board[i] = ' ';         //
    }
    k=0;
    for(int i=1;i<=9;i++)
    {
        if(board[i]!=' ')
            continue;
        board[i] = p;
        if(have_won(p))
        {
            board[i] = cp;
            return;
        }
        board[i] = ' ';
    }
    int fre[4],j=0;
    for(int i=1;i<=9;i += (i%3==0 ? 4 : 2))
    {
        if(board[i]==' ')
            {fre[j]=i;
            j++;
            }
    }
    if(j>0)
    {
        srand(time(0));
        board[fre[0+rand()%j]] = cp;
        return;
    }
    if(board[5] == ' ');
    {
        board[5] = cp;
        return;
    }

            j=0;
        for(int i=2;i<=8;i+=2)
        {
            if(board[i]==' ')
            {
            fre[j]=i;
            j++;}
        }
    if(j>0)
    {
        srand(time(0));
        board[fre[0+rand()%j]] = cp;
        return;
    }


}

int is_full()
{
    int j=0;
    for(int i=1;i<=9;i++)
    {
        if(board[i]!=' ')
            j++;
    }
    if(j==9)
        return 1;
    else
        return 0;
}

void inst()
{
    printf("You have to enter your move by entering value 1-9 as per your numlock keyboard\n");
        printf("Postions for entry of 'x' or 'o' is given by : \n");
        for(int i=1;i<=9;i++)
        {
            board[i] = (char)(i+48);
        }
        drawBoard();
        for(int i=1;i<=9;i++)
        {
            board[i] = ' ';
        }
        printf("Choose your letter x or o :");
}

void flush()
{
    for(int i=1;i<=9;i++)
        board[i]=' ';
}
void victory()
{
    printf("  _______\n");
    printf(" |       |\n");
    printf("(| CHAMP |)\n");
    printf(" |  #$   |\n");
    printf("  \\     /\n");
    printf("   `---'\n");
    printf("   _|_|_\n");
    printf("  /_____\\\n");
    printf("OUR CHAMP IS HERE \n\n");
}
/*
  _______
 |       |
(| CHAMP |)
 |  #$   |
  \     /
   `---'
   _|_|_
  /_____\
OUR CHAMP IS HERE
*/


int main()
{
        printf("This is TIC TAC TOE \n");
        drawBoard();
        int pa=1;
        int mov,turn;
        inst();
        scanf("%c",&p);
        cp = (p=='x' || p=='X') ? 'o' : 'x';
        srand(time(0));
        turn = 1+rand()%2;
    while(pa)
        {
        if(turn ==1 )
        {
            printf("Your turn \n");
        printf("Enter your move : ");
        scanf("%d",&mov);
        if(mov<10 && mov>0 && board[mov]==' ')   //new code
        board[mov] = p;
        else                                    //<--new code
        {
            printf("Invalid move\nTry again");
            continue;
        }                                       //new code -->
        drawBoard();
        turn = 2;
        }
        else
            {cpuMove();
            printf("Computer move \n");
            drawBoard();
            turn = 1;
            }
        if(have_won(p))
        {
            printf("Hurrey You won \n");
            victory();
            printf("Do you want to play again? (1 or 0 :: yes or no): ");
            scanf("%d",&pa);
            flush();
        }
        else if(have_won(cp))
        {
            printf("Computer has defeated you \n");
            printf("Do you want to play again? (1 or 0 :: yes or no): ");
            scanf("%d",&pa);
            flush();
        }
        else if(is_full())
        {
            printf("Game has been drawn. \n");
            printf("Do you want to play again? (1 or 0 :: yes or no): ");
            scanf("%d",&pa);
            flush();
        }
        }
    return 0;
}
