#include<iostream>
#include<array>
using namespace std;

int getsize(int input_sparse_matrix[4][5]){
	int column_size;
	int i=0;
	for (int i=0;i<4;i++){
		for (int j=0;j<5;j++){
			if(input_sparse_matrix[i][j]!=0){
				column_size++;
			}
		}
	}
	return column_size;
}

void outputmatrix(int column_size, int input_sparse_matrix[4][5]){
	int output_matrix[3][column_size];
	int k=0; 
	int i=0;
	while (i<4){
		int j=0;
		while(j<5){
			if(input_sparse_matrix[i][j]!=0){
				output_matrix[0][k] = i;  
                output_matrix[1][k] = j;  
                output_matrix[2][k] = input_sparse_matrix[i][j];  
                k++;  
			}
		 j++;
		}
		i++;
	}

	
	for(int i=0 ;i<3; i++)  
    {  
        for(int j=0; j<column_size; j++)  
        {  
            cout<< output_matrix[i][j];  
            cout<<"\t"; 
        }  
        cout<<"\n";  
    }  
}

int main(){
	int column_size = 0; 
	int input_sparse_matrix [4][5]= 
	{
		{0,0,3,0,4},
		{0,0,5,7,0},
		{0,0,0,0,0},
		{0,2,6,0,0}
	};
 	column_size= getsize(input_sparse_matrix);
	outputmatrix(column_size,input_sparse_matrix);
}