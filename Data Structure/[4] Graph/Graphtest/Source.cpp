#include <iostream>
using namespace std;

#define dim 7
#define inf 99

int weight[dim][dim] = { { 0 , 3 ,inf,inf,inf,inf, 5 },
						 { 3 , 0 , 2 ,inf,inf,inf, 5 },
						 {inf, 2 , 0 , 7 , 1 , 1 , 3 },
						 {inf,inf, 7 , 0 , 6 , 7 ,inf},
						 {inf,inf, 1 , 6 , 0 , 4 ,inf},
						 {inf,inf, 1 , 7 , 4 , 0 , 3 },
						 { 5 , 5 , 3 ,inf, 3 , 3 , 0 } };

void printMatrix(int matrix[dim][dim]){                        
	int r, c;
	for (c = 0; c < dim; c++)	cout << "\t" << c; cout << "\n";

	for (r = 0; r < dim; r++){
		cout << "\n" << r << "\t";
		for (c = 0; c < dim; c++){
			if (matrix[r][c] == inf)	           cout << "#\t";
			else	                        cout << matrix[r][c] << "\t";}}
	cout << "\n";
}

int kruskalMST(int weight[dim][dim]) {
	int min, rmin, cmin, totalWeight = 0, groupNo = 0, z[dim], mst[dim][dim];
   
	for (int r = 0; r < dim; r++){                                    //MST is new unconnected matrix rather than the previous to keep it
		for (int c = 0; c < dim; c++){
			if (r == c)	      mst[r][c] = 0;
			else	          mst[r][c] = inf;}}

	for (int r = 0; r < dim; r++) z[r] = -1;                     // vertical table of groups

	while (1) {
		min = inf;

		for (int r = 0; r < dim; r++) {                                                           
			for (int c = 0; c < r; c++) {
				if (min > weight[r][c]) { rmin = r;    cmin = c;    min = weight[r][c]; }}}   // used for obtaining the least edge weight and it's vertex

		if (min == inf) { cout << "\n\n Minimum Total Weight =" << totalWeight << endl << endl;   printMatrix(mst); return 0; }  // means there isn't other edges, so we finished

		if ( (z[rmin] != z[cmin]) || (z[rmin] == -1) || (z[cmin] == -1) ) {
			mst[rmin][cmin] = mst[cmin][rmin] = min;    totalWeight += min;       //building MST to be similar to the real matrix and finding it's total weight

			if ((z[rmin] == -1) && (z[cmin] == -1)) { groupNo++; z[rmin] = z[cmin] = groupNo; }  // updating the z table
			else if ((z[rmin] == -1) && (z[cmin] != -1))             z[rmin] = z[cmin];
			else if ((z[cmin] == -1) && (z[rmin] != -1))             z[cmin] = z[rmin];
			else { for (int i = 0; i < dim; i++)   if (z[i] == z[cmin]) z[i] = z[rmin]; }  //taw7eed el tarabeezat
		}
		weight[rmin][cmin] = inf;    // editing the real matrix to prevent repeating the previous methods with the same edge
	}
}

void primMST(int weight[dim][dim]) {
	int z[dim][3], r, c, min, rmin, newmin, totalWeight = 0, mst[dim][dim];
	
	for (r = 0; r < dim; r++)
		for (c = 0; c < dim; c++){
		  if (r == c) mst[r][c] = 0;
		  else	     mst[r][c] = inf;}

	for (r = 0; r < dim; r++) { z[r][0] = -1;   z[r][1] = inf;   z[r][2] = 0; }

	rmin = 0;    min = weight[rmin][rmin];   z[rmin][0] = 0; z[rmin][1] = 0; z[rmin][2] = 1;

	do {
		for (r = 0; r < dim; r++)
			if ((z[r][2] == 0) && (z[r][1] > weight[rmin][r]))    { z[r][0] = rmin; z[r][1] = weight[rmin][r]; }

		    min = inf; newmin = -1;
			
			for (r = 0; r < dim; r++)  if ((z[r][2] == 0) && (z[r][1] < min))        { min = z[r][1]; rmin = z[r][0]; newmin = r; }

			if (min == inf)	break;

		mst[rmin][newmin] = mst[newmin][rmin] = weight[rmin][newmin];     totalWeight = totalWeight + min;

		cout << "\n   rmin=" << rmin << "   newmin=" << newmin << "   min="<< min << "\n";
		rmin = newmin;

		for (r = 0; r < dim; r++) { cout << r << "\t" << z[r][0] << "\t" << z[r][1] << "\t" << z[r][2] << "\n"; }

		z[rmin][2] = 1;
	} while (rmin != -1);

	cout << "\nMinimum Total Weight = " << totalWeight << "\n";        printMatrix(mst);
}

void shortestPath(int weight[dim][dim],int source,int des) {
	int z[dim][3],r, min, rmin;

	for (r = 0; r < dim; r++)  {z[r][0] = -1; z[r][1] = inf; z[r][2] = 0;}

	rmin = source;     min = weight[rmin][rmin];     z[source][0] = source;     z[source][1] = 0;

	do {
		z[rmin][2] = 1;
		for (r = 0; r < dim; r++) {   if ((z[r][2] == 0) && (z[r][1] > (weight[rmin][r] + min))) {z[r][1] = weight[rmin][r] + min; z[r][0] = rmin;}   } 

		min = inf; rmin = -1; 
		for (r = 0; r < dim; r++)  {   if ((z[r][2] == 0) && (z[r][1] < min)) {min = z[r][1]; rmin = r;}   }
	} while (rmin != des);

	cout << "\n Final Result "; r = des;    cout << "\t" << r;

	while (r != source) { r = z[r][0];    cout << "\t" << r; }

	cout << "\n";  cout << min;
}

void alltoallShortestPath(int weight[dim][dim]) {
	int r, c, flag;
	for (r = 0; r < dim; r++) {
		for (c = 0; c < dim; c++)
			if (weight[r][c] == inf)	             cout << "#\t";
			else                      	cout << weight[r][c] << "\t";    cout << "\n";}

	do {
		flag = 0;
		for (int src = 0; src < dim; src++)
			for (int dest = 0; dest < dim; dest++) for (int via = 0; via < dim; via++)
				if (weight[src][dest] > weight[src][via] + weight[via][dest]) { weight[src][dest] = weight[src][via] + weight[via][dest]; flag++; }
		cout << "Flag = " << flag << endl;
	} while (flag > 0);

	cout << "\n\n";
	for (r = 0; r < dim; r++) {
		for (c = 0; c < dim; c++)
			cout << weight[r][c] << "\t"; cout << "\n";
	}
}


int main(void){
	//int source, des;
	//cout << "Enter the source point ";   cin >> source;     cout << "Enter the destination point ";   cin >> des;


	cout << "\n******************************* Graph matrix ***********************************\n";
	printMatrix(weight);

	//cout << "\n***************************** PRIM Algorithm ******************************\n";
	//primMST(weight);

	//cout << "\n***************************** KRUSKAL Algorithm ******************************\n";
	//kruskalMST(weight);

	cout << "\n************************Shortest path between two nodes*************************\n";
	shortestPath(weight, 2, 5);

	//cout << "\n************************** all to all shortest path **************************\n";
	//alltoallShortestPath(weight);

}

























/* else	          mst[r][c] = inf; }}   */
//cout << "\n\n"; printMatrix(mst);  unconnected matrix