#include "colormod.h" // namespace Color
/*
Ian Flanagan
Word Search
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;


void hor(vector<vector<char>> &matrix, char *word, vector<vector<int>> &position)
{ 
    
    int wordLength = strlen(word); // Initialize position matrix 
    
    for(int row = 0; row < matrix.size(); row++) 
    { 
        for(int col = 0; col < matrix[0].size(); col++) 
        { // Check downwards 
            if(row + wordLength <= matrix[0].size()) 
            { 
                bool matchRight = true;
                for(int i = 0; i < wordLength; i++)
                {
                    if(matrix[row][col+i] != word[i])
                    {
                        matchRight = false;
                        break;
                    }
                }

                if(matchRight)
                {
                    for(int i = 0; i < wordLength; i++)
                    {
                        position[row][col+i] = 1;
                    }
                }
            }
            if(col - wordLength >= -1)
            {
                bool matchLeft = true;
                for(int i = 0; i < wordLength; i++)
                {
                    if(matrix[row][col-i] != word[i])
                    {
                        matchLeft = false;
                        break;
                    }
                }

                if(matchLeft)
                {
                    for(int i = 0; i < wordLength; i++)
                    {
                        position[row][col-i] = 1;
                    }
                }
            }
        }
    }
}
void vert(vector<vector<char>> &matrix, const char *word, vector<vector<int>> &position) 
{ 
    int wordLength = strlen(word); // Initialize position matrix 
    
    for(int col = 0; col < matrix[0].size(); col++) 
    { 
        for(int row = 0; row < matrix.size(); row++) 
        { // Check downwards 
            if(row + wordLength <= matrix.size()) 
            { 
                bool matchDown = true;
                for(int i = 0; i < wordLength; i++)
                {
                    if(matrix[row+i][col] != word[i])
                    {
                        matchDown = false;
                        break;
                    }
                }

                if(matchDown)
                {
                    for(int i = 0; i < wordLength; i++)
                    {
                        position[row+i][col] = 1;
                    }
                }
            }
            if(row - wordLength >= -1)
            {
                bool matchUp = true;
                for(int i = 0; i < wordLength; i++)
                {
                    if(matrix[row-i][col] != word[i])
                    {
                        matchUp = false;
                    }
                }

                if(matchUp)
                {
                    for(int i = 0; i < wordLength; i++)
                    {
                        position[row-i][col] = 1;
                    }
                }
            }
        }
    }
}
void dia(vector<vector<char>> &matrix, char *word, vector<vector<int>> &position)
{
    int wrdLen = strlen(word);

    for(int row = 0; row < matrix.size(); row++)
    {
        for(int col = 0; col < matrix[0].size(); col++)
        {
            if((row + wrdLen <= matrix.size()) && (col + wrdLen <= matrix[0].size()))
            {
                bool matchDR = true;
                for(int i = 0; i < wrdLen; i++)
                {
                    if(matrix[row+i][col+i] != word[i])
                    {
                        matchDR = false;
                        break;
                    }
                }

                if(matchDR)
                {
                    for(int i = 0; i < wrdLen; i++)
                    {
                        position[row+i][col+i] = 1;
                    }
                }
            }

            if((row - wrdLen >= -1) && (col - wrdLen >= -1))
            {
                bool matchUL = true;
                for(int i = 0; i < wrdLen; i++)
                {
                    if(matrix[row-i][col-i] != word[i])
                    {
                        matchUL = false;
                        break;
                    }
                }

                if(matchUL)
                {
                    for(int i = 0; i < wrdLen; i++)
                    {
                        position[row-i][col-i] = 1;
                    }
                }
            }

            if((row + wrdLen <= matrix.size()) && (col - wrdLen >= -1))
            {
                bool matchDL = true;
                for(int i = 0; i < wrdLen; i++)
                {
                    if(matrix[row+1][col-i] != word[i])
                    {
                        matchDL = false;
                        break;
                    }
                }

                if(matchDL)
                {
                    for(int i = 0; i < wrdLen; i++)
                    {
                        position[row+i][col-i] = 1;
                    }
                }
            }

            if((row - wrdLen >= -1) && (col + wrdLen <= matrix[0].size()))
            {
                bool matchUR = true;
                for(int i = 0; i < wrdLen; i++)
                {
                    if(matrix[row-i][col+i] != word[i])
                    {
                        matchUR = false;
                        break;
                    }
                }
                if(matchUR)
                {
                    for(int i = 0; i < wrdLen; i++)
                    {
                        position[row-i][col+i] = 1;
                    }
                }
            }
        }
    }

}

int main(int argc, char *argv[])
{
    vector< vector<char>> arr;
    vector<vector<int>> position;
    int vx, vy;
    
    cin >> vx;
    cin >> vy;
    
    arr.resize(vx);
    position.resize(vx);
    for(int i = 0; i < vx; i++)
    {
        arr[i].resize(vy);
        position[i].resize(vy);
    }
    
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
        {
            cin >> arr[i][j];
        }
    } 
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
        {
            position[i][j] = 0;
        }
    }
    
    for(int i = 1; i < argc; i++)
    {
        hor(arr, argv[i], position);
        vert(arr, argv[i], position); 
        dia(arr, argv[i], position);
    }
    

    Color::Setting red(Color::FG_RED);
    Color::Setting def(Color::FG_DEFAULT);
    
    for(int i = 0; i < arr.size(); i++)
    {
        cout << endl;
        for(int j = 0; j < arr[0].size(); j++)
        {
            if(position[i][j] == 1)
                cout << red << arr[i][j] << def << " ";
            else
                cout << arr[i][j] << " ";
        }
    }
    
    return 0;
}