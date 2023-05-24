#include "mlp.hpp"

using namespace std;

int main()
{
    // set hyper parameters
    int epoch, input_size, output_size, weight_dim;
    double threshold, learning_rate;

    epoch = 10;
    input_size = 2;
    output_size = 2;
    weight_dim = 2;
    threshold = 0.3;
    learning_rate = 0.01;

    cout << "Check1" << endl;
    MultiPerceptronLayer mlp(epoch, input_size, output_size, weight_dim, learning_rate, threshold);
    
    cout << "\nforwarding test: print foward output, after softmax calculate is done\n";
    for(double v : mlp.forward())
        cout << v << endl;
    cout << "\nCheck2" << endl;

    

    return 0;
}