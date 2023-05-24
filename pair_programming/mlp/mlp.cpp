#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class MultiPerceptronLayer
{
    public:
        MultiPerceptronLayer(int epoch, vector<double> inputs, double threshold, int inputSize, int outputSize, int weight_dim, int learningRate)
        {
            weights1.resize(weight_dim, vector<double>(weight_dim, 0));    // vector size initilize
            weights1[0][0] = 0.1;
            weights1[0][1] = 0.2;
            weights1[1][0] = 0.3;
            weights1[1][1] = 0.4;

            weights2.resize(weight_dim, vector<double>(weight_dim, 0));    // vector size initilize
            weights2[0][0] = 0.1;
            weights2[0][1] = 0.2;
            weights2[1][0] = 0.3;
            weights2[1][1] = 0.4;

            threshold = threshold;

            inputs = inputs;
            epoch = epoch;

            cout << weights1[0][1] << endl;
        }

        auto sigmoid(double x) -> double
        {
            return 1.0 / (1.0 - exp(-x));
        }

        auto forward() -> vector<double>
        {
            vector<double> ffnn_output;

            for(int i=0; i<outputSize; i++)
            {
                double cur_sum = 0.0;

                for(int j; j<inputSize; j++)
                    cur_sum += inputs[j] * weights1[i][j];
                    
                ffnn_before_output1[i] = cur_sum;
                //ffnn_output[i] = sigmoid(cur_sum);
                ffnn_output.push_back(sigmoid(cur_sum));
            }

            for(int i=0; i<outputSize; i++)
            {
                double cur_sum = 0.0;
                for(int j; j<inputSize; j++)
                    cur_sum += ffnn_output[j] * weights2[i][j];

                ffnn_before_output2[i] = cur_sum;
                output[i] = cur_sum;
            }
            

            return output; // sigmoid 통과하기 전 z들 => 저장할건지?
        }
        
        /*
        auto backword(vector<double> output) -> vector<double>
        {
            vector<double> forward_output = forward();
            
            double gab = 1.0;
            gab *= -(y1 - sigmoid(forward_output[0]));
            gab *= -(y1 - sigmoid(forward_output[0]));


            weights[0][0] = weights[0][0] - learningRate * gab;
        }
        */

        /*
        double learning()
        {
            return abs(forward() - backword());
        }

        void model_learning()
        {   
            for(int i = 0; i < epoch; i++)
                if(learning() < threshold) break;
        }
        */

    private:
        vector<vector<double>> weights1;
        vector<vector<double>> weights2;
        vector<double> ffnn_before_output1;
        vector<double> ffnn_before_output2;
        vector<double> inputs;
        vector<double> output;
        int epoch;
        int inputSize;
        int outputSize;
        int weight_dim;
        int learningRate;
        double threshold;
};

int main(int argv, char**argc){
    int epoch = 10;
    int inputSize = 2;
    int outputSize = 2;
    int weight_dim = 2;
    int learningRate= 0.5;
    double threshold = 0.3;

    vector<double> inputs;
    inputs[0] = 0.5;
    inputs[1] = 0.4;
    //inputs[2] = 0.8;

    MultiPerceptronLayer mlp(epoch, inputs, threshold, inputSize, outputSize, weight_dim, learningRate);

    cout << "Hello\n";
    
    for(double w : mlp.forward())
    {
        cout << w << endl;
    }

    return 0;
}