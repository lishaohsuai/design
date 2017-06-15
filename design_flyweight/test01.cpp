#include<iostream>
#include<vector>
using namespace std;
//棋子的颜色
enum PieceColor { BLACK, WHITE};
//棋子的位置
struct PiecePos
{
    int x;
    int y;
    PiecePos(int a, int b): x(a), y(b){}
};
//棋子的定义
class Piece
{
    protected:
        PieceColor m_color;//颜色
        PiecePos m_pos;    //位置
    public:
        Piece(PieceColor color, PiecePos pos):m_color(color), m_pos(pos){}
        ~Piece(){}
        virtual void Draw(){}
};
class BlackPiece:public Piece
{
    public:
        BlackPiece(PieceColor color, PiecePos pos):Piece(color, pos){}
        ~BlackPiece(){}
        void Draw()
        {
            cout<<"绘制一颗黑棋"<<endl;
        }
};
class WhitePiece:public Piece
{
    public:
        WhitePiece(PieceColor color, PiecePos pos):Piece(color, pos){}
        ~WhitePiece(){}
        void Draw()
        {
            cout<<"绘制一颗白棋"<<endl;
        }
};

class PieceBoard
{
    private:
        vector<Piece*>m_vecPiece;//棋盘上已有的棋子
        string m_blackName;//黑方执手
        string m_whiteName;//白方执手
    public:
        PieceBoard(string black, string white):m_blackName(black), m_whiteName(white){}
        ~PieceBoard(){Clear();}
        void SetPiece(PieceColor color, PiecePos pos)//一步棋在棋盘放一颗棋子
        {
            Piece *piece = NULL;
            if(color == BLACK)//黑方下的
            {
                piece = new BlackPiece(color, pos);//火气一颗黑棋
                cout<<m_blackName<<"在位置{"<<pos.x<<','<<pos.y<<")";
                piece->Draw();
            }
            else
            {
                piece = new WhitePiece(color, pos);
                cout<<m_whiteName<<"在位置("<<pos.x<<pos.y<<")";
                piece->Draw();
            }
            m_vecPiece.push_back(piece); //加入容器中
        }
        void  Clear() //释放内存
        {
            int size = m_vecPiece.size();
            for(int i = 0; i < size; i++)
            {
                delete m_vecPiece[i];
            }
        }
};
int main()
{
    PieceBoard pieceBoard("A","B");
    pieceBoard.SetPiece(BLACK, PiecePos(4, 4));
    pieceBoard.SetPiece(WHITE, PiecePos(4, 16));
    pieceBoard.SetPiece(BLACK, PiecePos(4, 4));
    pieceBoard.SetPiece(WHITE, PiecePos(4, 16));
}


