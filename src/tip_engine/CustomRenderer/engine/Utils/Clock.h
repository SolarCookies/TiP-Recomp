#pragma once
//This class provides simple clock functionality for measuring elapsed time, useful for profiling and timing operations

#include <chrono>
#include <functional>
#include <thread>

class Clock {
	public:
	Clock() : start_time(std::chrono::high_resolution_clock::now()) {}
	// Resets the clock to the current time
	void Reset() {
		start_time = std::chrono::high_resolution_clock::now();
	}
	// Returns the elapsed time in seconds since the last reset
	float Time() const {
		auto current_time = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = current_time - start_time;
		return duration.count();
	}
	void AsyncDelay(float seconds, std::function<void()> callback) {
		std::thread([seconds, callback]() {
			std::this_thread::sleep_for(std::chrono::duration<float>(seconds));
			callback();
		}).detach();
	}

	// Fun names
	void StartLap() {
		start_time = std::chrono::high_resolution_clock::now();
	}
	float EndLap() {
		auto end_time = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end_time - start_time;
		return duration.count();
	}
private:
	std::chrono::high_resolution_clock::time_point start_time;
};