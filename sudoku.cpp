bool checkblock(int matrix[9][9],int row,int col,int element)
{
	int startcol;
	int endcol;
	int startrow;
	int endrow;
	if((row/3)==0)
	{
		startrow=0;
		endrow=2;
	}
	else if((row/3)==1)
	{
		startrow=3;
		endrow=5;
	}
	else
	{
		// cout<<element<<endl;
		startrow=6;
		endrow=8;
	}
	if((col/3)==0)
	{
		startcol=0;
		endcol=2;
	}
	else if((col/3)==1)
	{
		startcol=3;
		endcol=5;
	}
	else
	{
		startcol=6;
		endcol=8;
	}
	// cout<<startrow<<" "<<startcol<<endl; 
	for(int i=startrow;i<=endrow;i++)
	{
		for(int j=startcol;j<=endcol;j++)
		{
			if(matrix[i][j]==element)
			{
				return true;
			}
		}
	}
	return false;
}

bool findelementrow(int matrix[9][9],int row,int element)
{
	for(int i=0;i<9;i++)
	{
		if(matrix[row][i]==element)
		{
			return true;
		}
	}
	return false;
}

bool findelementcol(int matrix[9][9],int col,int element)
{

	for(int i=0;i<9;i++)
	{
		if(matrix[i][col]==element)
		{
			return true;
		}
	}
	return false;
}

bool findans(int matrix[9][9],int row,int col)
{
	if(row==9)
	{
		return true;
	}
	if(col==9)
	{
		return findans(matrix,row+1,0);
	}
	if(matrix[row][col]!=0)
	{
		return findans(matrix,row,col+1);
	}
	else
	{
		for(int i=1;i<=9;i++)
		{
			if(findelementrow(matrix,row,i))
			{
				continue;
			}
			if(findelementcol(matrix,col,i))
			{
				continue;
			}
			if(checkblock(matrix,row,col,i))
			{
				continue;
			}
			matrix[row][col]=i;
			// cout<<row<<" "<<col<<" "<<matrix[row][col]<<endl;
			if(findans(matrix,row,col+1))
			{
				return true;
			}
			matrix[row][col]=0;
		}
		return false;
	}
}

bool isItSudoku(int matrix[9][9]) 
{
	bool ans=findans(matrix,0,0);
	return ans;
}
