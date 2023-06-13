cmake_minimum_required(VERSION 3.25)
project(CRYPTO_BACKTEST C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

file(GLOB SOURCE src/*.c)
file(GLOB CSV src/csv/*.c)
file(GLOB FILES src/file/*.c)
file(GLOB BACKTEST src/backtest/*.c)
file(GLOB INDICATORS src/indicators/*.c)
file(GLOB KLINES src/klines/*.c)
file(GLOB LIB_LIST lib/list/*.c)
file(GLOB STRATEGIES strategies/*.c)

file(GLOB HEADER include/*.h)

add_executable(backtest ${SOURCE} ${CSV} ${FILES} ${BACKTEST} ${INDICATORS} ${KLINES} ${LIB_LIST} ${STRATEGIES} ${HEADER})
