#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iomanip>

using namespace std;

vector< pair< int, int > > DIMS = { 
    {9,13},
    {10,15},
    {13,13}, {13,18}, {13,25}, {13,30},
    {15,15}, {15,21}, {15,25}, {15,45},
    {20,30},
    {21,30},
    {25,30},
    {30,30}, {30,40}, {30,45}
};

template< typename T >
const T& min( const pair< T, T >& p )
{
	return min( p.first, p.second );
}

template< typename T >
const T& max( const pair< T, T >& p )
{
	return max( p.first, p.second );
}


void fit( int userDim1, int userDim2, const pair< int, int > & reqDims )
{
    double userMaxByMin = ( (double)max( userDim1, userDim2 ) / min( userDim1, userDim2 ) );


    cout << setprecision(4);
    string marker;

    double tmp = (double)min( reqDims ) * userMaxByMin;
    double diff = tmp-max(reqDims);
    diff = (abs(diff) > 0.01 ? diff : 0);
    cout << min( reqDims ) << "x" << tmp << "(" << diff << ")";
    marker = (diff == 0 ? "*" : "");

    cout << " or ";

    tmp = (double)max( reqDims ) * ( 1/userMaxByMin );
    diff = tmp-min(reqDims);
    diff = (abs(diff) > 0.01 ? diff : 0);
    cout << tmp << "(" << diff << ")" << "x" << max( reqDims );
    marker += (diff == 0 ? "*" : "");

    cout << " on " << get< 0 >( reqDims ) << "x" << get< 1 >( reqDims ) << " " << marker << endl;
}

int main( int argc, char* argv[] )
{
   cout << "Hello World" << endl;
   cout << argc << endl;

   int dim1 = atoi( argv[1] );
   int dim2 = atoi( argv[2] );

   
   for ( const auto & dim: DIMS )
	   fit( dim1, dim2, dim );
   
   return 0;
}


