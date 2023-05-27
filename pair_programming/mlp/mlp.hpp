#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class MultipleLayerPerceptron
{
public:
    MultipleLayerPerceptron(int _epoch, int _input_size, int _output_size, int _weight_dim, double _learning_rate, double _threshold) : 
    epoch(_epoch), 
    input_size(_input_size), 
    output_size(_output_size), 
    weight_dim(_weight_dim), 
    learning_rate(_learning_rate), 
    threshold(_threshold),
    weight_vector(_weight_dim, vector<double>(_weight_dim, 0.0))
    {
        // input vector 
        input_vector.push_back(1.0);
        input_vector.push_back(2.0);

        // layer1
        weight_vector[0][0] = 0.1;
        weight_vector[1][0] = 0.2;
        
        // layer2
        weight_vector[0][1] = 0.3;
        weight_vector[1][1] = 0.4;
    }

    auto sigmoid(double x) -> double
    {
        return 1.0 / (1.0 + exp(-x)); 
    }

    auto softmax(const vector<double>& logits) -> vector<double>
    {
        double sumExp = 0.0;
        vector<double> predicates;
        double max_logit = *max_element(logits.begin(), logits.end());  // get max value in logits


        for (size_t i = 0; i < logits.size(); i++) 
        {
            double expValue = exp(logits[i] - max_logit); // calculate exp, except max logit(to make stable condition)
            sumExp += expValue;
            predicates.push_back(expValue);
        }

        for (size_t i = 0; i < predicates.size(); i++)
            predicates[i] /= sumExp;    // value normalizing

        return predicates;
    }

    auto cross_entropy(const vector<double>& predicates) -> double
    {
        double loss = 0.0;

        for (size_t i = 0; i< predicates.size(); i++)
            loss += input_vector[i] * log(predicates[i]);

        loss = -loss / predicates.size();

        return loss;
    }

    auto forward() -> vector<double>
    {
        vector<double> ffnn_output1;
        vector<double> ffnn_output2;

        for(int i=0; i<weight_dim; i++) //  calculate layer1
        {
            double node_value = 0;

            for (int j=0; j<input_size; j++)
                node_value += input_vector[j] * weight_vector[i][0];

            ffnn_output1.push_back(sigmoid(node_value));
        }

        for (int i=0; i<weight_dim; i++) //  calculate layer2
        {
            double node_value = 0;

            for (int j=0; j<input_size; j++)
                node_value += ffnn_output1[j] * weight_vector[i][1];

            ffnn_output2.push_back(node_value);
        }

        return softmax(ffnn_output2);
    }

    void learn(int input_size, int output_size, int weight_dim)
    {   
        
        // forward
        vector<double> output = forward();

        // Backward 계산
        vector<double> gradient;
        for (int i = 0; i < output_size; i++) {
            double g = output[i] * (1.0 - output[i]) * (output[i] - input_vector[i]);
            gradient.push_back(g);
        }

        // 가중치 업데이트
        vector<vector<double>> weightUpdate(weight_dim, vector<double>(input_size, 0));

        for (int i = 0; i < weight_dim; i++) {
            for (int j = 0; j < input_size; j++) {
                weightUpdate[i][0] = learning_rate * gradient[i] * input_vector[j];
            }
        }

        // 가중치 업데이트
        for (int i = 0; i < weight_dim; i++) {
            for (int j = 0; j < input_size; j++) {
                weight_vector[i][0] += weightUpdate[i][0];
            }
        }
    }

    void learning(int epoch)
    {
        for(int i = 0; i<epoch; i++)
        {
            learn(input_size, output_size, weight_dim);

            show_weights(i);

            if (weight_vector[0][0] < threshold) // 여기 cross_entropy를 이용하나?
                break;
        }
    }

    void show_weights(int i)
    {
        cout << i << "th weight_vectors" << endl;
        cout << "weight_vector[0][0] : " << weight_vector[0][0] << endl;
        cout << "weight_vector[0][1] : " << weight_vector[0][1] << endl;
        cout << "weight_vector[1][0] : " << weight_vector[1][0] << endl;
        cout << "weight_vector[1][1] : " << weight_vector[1][1] << endl;
    }

private:
    int epoch;
    int input_size;
    int output_size;
    int weight_dim;
    double learning_rate;
    double threshold;    
    vector<double> input_vector;
    vector<double> output_vector;
    vector<vector<double>> weight_vector;
};
