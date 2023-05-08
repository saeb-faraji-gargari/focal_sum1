cmake_minimum_required(VERSION 3.5)

project(focal_sum)   # esme project kheili mohem nist ye esmi baraye khode cmake hast


############################################################
# Create an executable
############################################################

# Add an executable with the above sources  # inja yek barname be esme 'hello_library_esme_barname_execute_shode_run' ra execute ye barye run amade mikonad
add_executable(${PROJECT_NAME}   #${PROJECT_NAME} mishe ye esme dige ham be jaye '${PROJECT_NAME}' estefade karfd vali in mamol hast engar
    #src/main.cpp
	
	#src/test2.cpp
	
	#src/test_1_CLA.cpp
	
	src/main.cpp
)



############################################################
# Create a library
############################################################

#Generate the static library from the library sources ### inja ye liberary be project 'hello_library_esme_project_ast' ezafe mikonad
add_library(Name_library STATIC  # +++++in functionhaye lazem ra dar yed bakhsh be esme 'esme_library' grohbandi mikonad
    #src/GDAL_focal_sum.cpp
	#src/GDAL_focal_sum_test.cpp
    #src/add_test.cpp
	src/GDAL_focal_sum_3_to_3.cpp
	#src/GDAL_focal_sum_3_to_3_test.cpp
	
)


target_include_directories(Name_library     #chon barnayeye ya function Hello.cpp be header Hello.h ke dar address '${PROJECT_SOURCE_DIR}/include' hast niyaz darad dar 'esme_library' add directory darnazar gerefte shode ast
    PUBLIC                                                    #in includ haye lazem mesle header file ra ezafe mikonad
        ${PROJECT_SOURCE_DIR}/include
)

#inja include haye lazem baraye 'hello_library_esme_project_ast' farakhani mikonad masalan inja dar folder include hastand
#target_include_directories(Name_library     #chon barnayeye ya function Hello.cpp be header Hello.h ke dar address '${PROJECT_SOURCE_DIR}/include' hast niyaz darad dar 'esme_library' add directory darnazar gerefte shode ast
#    PUBLIC                                                    #in includ haye lazem mesle header file ra ezafe mikonad
#        ${PROJECT_SOURCE_DIR}/include
#)


#find_package(PkgConfig REQUIRED)
#pkg_check_modules(GDAL REQUIRED gdal)


# find system installed GDAL package with predefined CMake variable for finding GDAL
find_package(GDAL REQUIRED)

#find_package(Boost REQUIRED)

find_package(Boost 1.40 COMPONENTS program_options REQUIRED)

#find_package(Boost 1.68 REQUIRED)
#add_executable(foo foo.cpp)
#target_link_libraries(foo PUBLIC Boost::boost)

    
# Specify location of GDAL header files
include_directories(  

${GDAL_INCLUDE_DIRS}

${Boost_INCLUDE_DIR})

#INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

    
# Specify GDAL libraries to link your cpp executable target against
target_link_libraries(${PROJECT_NAME} 

Name_library 

${GDAL_LIBRARIES}

${Boost_PROGRAM_OPTIONS_LIBRARY}

${Boost_LIBRARIES} 

)


# enable testing functionality
enable_testing()
# testing binary
add_executable(Name_test 

src/test.cpp)

#target_link_libraries(cpp_test PRIVATE sum_integers)
# define tests
add_test(
  NAME Name_add_test
  COMMAND $<TARGET_FILE:Name_test>
  )
#add_test(Name_add_test Name_test) 
  



#find_package( Boost 1.30 COMPONENTS program_options REQUIRED )
#target_include_directories( myTarget PRIVATE ${Boost_INCLUDE_DIR})
#target_link_libraries( myTarget ${Boost_LIBRARIES} )


#find_package(GDAL CONFIG REQUIRED)


# link the new hello_library target with the hello_binary target
#target_link_libraries( ${PROJECT_NAME}   # +++++ in migoyad kodam libarary ba kodam execute link ast
   
#   PRIVATE 
	    
#		GDAL::GDAL
#       Name_library
#)

