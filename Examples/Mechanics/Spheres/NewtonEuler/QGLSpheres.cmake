SET(WithQGLViewer TRUE)
SET(WithOpenGL TRUE)

  IF(X11_FOUND)	
    FIND_PACKAGE_MESSAGE(X11 "Found X11: ${X11_X11_LIB}"
      "[${X11_X11_LIB}][${X11_INCLUDE_DIR}]")
  ELSE (X11_FOUND)	
    IF (X11_FIND_REQUIRED)	
      MESSAGE(FATAL_ERROR "Could not find X11")
    ENDIF (X11_FIND_REQUIRED)	 
  ENDIF (X11_FOUND)

  IF(OPENGL_FOUND)	
    FIND_PACKAGE_MESSAGE(OpenGL "Found OpenGL: ${OPENGL_LIBRARIES} ${OPENGL_INCLUDE_DIR}"
      "[${OPENGL_INCLUDE_DIR}]")
  ELSE (OPENGL_FOUND)	
    IF (OPENGL_FIND_REQUIRED)	
      MESSAGE(FATAL_ERROR "Could not find OPENGL")
    ENDIF (OPENGL_FIND_REQUIRED)	 
  ENDIF (OPENGL_FOUND)		 

FIND_PACKAGE(SiconosMechanics REQUIRED)
INCLUDE_DIRECTORIES(${SiconosMechanics_INCLUDE_DIRS})
LINK_DIRECTORIES(${SiconosMechanics_LIBRARY_DIRS})
LIST(APPEND LINKER_OPTIONS ${SiconosMechanics_LIBRARIES})
