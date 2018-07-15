ADD_EXECUTABLE(dotProduct
               $<TARGET_OBJECTS:dotp>
               dotProductBenchmark.cc)
TARGET_LINK_LIBRARIES(dotProduct benchmark)

ADD_EXECUTABLE(dotProduct_test
               $<TARGET_OBJECTS:dotp>
               dotProductTest.cc)
TARGET_LINK_LIBRARIES(dotProduct_test gtest)

INSTALL(TARGETS dotProduct dotProduct_test
        RUNTIME DESTINATION ${INSTALL_DIR})
