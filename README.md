This is a very simple logger in and for C++ which can be used to log Traces and 
Levels:  
Traces can be exported (thus enabled) like so: `export TRACES=TEST`  
Logging on Traces which are not exported will result in no logging at all.  
You can easily add Levels by modifying Logger.hpp's `enum class LVL` to your
liking.  
View main.cpp for an example.   

This code is licensed under the MIT License.  
You should have received a copy with this code.  
