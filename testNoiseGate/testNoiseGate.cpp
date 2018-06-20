// testNoiseGate.cpp: 定义控制台应用程序的入口点。
// 功能: 整合basic noiseGate effect，并进行封装及测试
// 

#include "stdafx.h"
#include <iostream>
#include "NoiseGate.h"
#include "AudioFile.cpp"
#include <vector>
using namespace std;

int main()
{
	AudioFile<double> af;
	string directory = ".\\assets\\";
	string file_name = "audio_in_with_noise.wav";
	af.load(directory + file_name);
	af.printSummary();
	vector<double> output;
	noise_gate_buff NG;
	// 单点处理
	for (auto sample : af.samples[0]) {
		output.push_back(noiseGate(sample, NG));
	}
	vector<vector<double>> audio_buff{output};			// 打包
	af.setAudioBuffer(audio_buff);
	af.save(directory+"after_noise_gate01.wav");
    return 0;
}
// 本例程用于验证 audioFile库+noiseGate算法是否能正常运行(测试通过)
