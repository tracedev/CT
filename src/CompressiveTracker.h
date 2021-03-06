/************************************************************************
* File: CompressiveTracker.h
* Brief: C++ demo for paper: Kaihua Zhang, Lei Zhang, Ming-Hsuan Yang,"Real-Time Compressive Tracking," ECCV 2012.
* Version: 1.0
* Author: Yang Xian
* Email: yang_xian521@163.com
* Date: 2012/08/03
* History:
* Revised by Kaihua Zhang on 14/8/2012, 23/8/2012
* Email: zhkhua@gmail.com
* Homepage: http://www4.comp.polyu.edu.hk/~cskhzhang/
* Project Website: http://www4.comp.polyu.edu.hk/~cslzhang/CT/CT.htm
************************************************************************/
#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

#define MAX_PATH 4096

class CompressiveTracker {
public:
    float radioMax;
    float learnRate;
    int rSearchWindow;
    CompressiveTracker();
    ~CompressiveTracker();

private:
    int featureMinNumRect;
    int featureMaxNumRect;
    int featureNum;
    std::vector<std::vector<cv::Rect> > features;
    std::vector<std::vector<float> > featuresWeight;
    int rOuterPositive;
    std::vector<cv::Rect> samplePositiveBox;
    std::vector<cv::Rect> sampleNegativeBox;
    cv::Mat imageIntegral;
    cv::Mat samplePositiveFeatureValue;
    cv::Mat sampleNegativeFeatureValue;
    std::vector<float> muPositive;
    std::vector<float> sigmaPositive;
    std::vector<float> muNegative;
    std::vector<float> sigmaNegative;
    std::vector<cv::Rect> detectBox;
    cv::Mat detectFeatureValue;
    cv::RNG rng;

private:
    void HaarFeature(cv::Rect& _objectBox, int _numFeature);
    void sampleRect(cv::Mat& _image, cv::Rect& _objectBox, float _rInner, float _rOuter, int _maxSampleNum, std::vector<cv::Rect>& _sampleBox);
    void sampleRect(cv::Mat& _image, cv::Rect& _objectBox, float _srw, std::vector<cv::Rect>& _sampleBox);
    void getFeatureValue(cv::Mat& _imageIntegral, std::vector<cv::Rect>& _sampleBox, cv::Mat& _sampleFeatureValue);
    void classifierUpdate(cv::Mat& _sampleFeatureValue, std::vector<float>& _mu, std::vector<float>& _sigma, float _learnRate);
    void radioClassifier(std::vector<float>& _muPos, std::vector<float>& _sigmaPos, std::vector<float>& _muNeg, std::vector<float>& _sigmaNeg,
                         cv::Mat& _sampleFeatureValue, float& _radioMax, int& _radioMaxIndex);
public:
    void processFrame(cv::Mat& _frame, cv::Rect& _objectBox);
    void init(cv::Mat& _frame, cv::Rect& _objectBox);
};
