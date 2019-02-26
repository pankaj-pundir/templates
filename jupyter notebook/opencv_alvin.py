import cv2
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sb

# image alteration

def kernel_ones(a,b):
    return np.ones((a,b),np.uint8)

def cuber_effect(image,frame_size=(480,848),kernel_size=(10,14)):
    '''frame_size input size of frame in tuple , kernel size in tuple x and y axis'''
    no_of_cubes=(int(frame_size[0]/kernel_size[0]),int(frame_size[1]/kernel_size[1]))
    for i in range(no_of_cubes[0]):
        for j in range(no_of_cubes[1]):
            image[i*kernel_size[0]:(i+1)*kernel_size[0],j*kernel_size[1]:(j+1)*kernel_size[1]]=\
            cv2.flip(image[i*kernel_size[0]:(i+1)*kernel_size[0],j*kernel_size[1]:(j+1)*kernel_size[1]],1)
    return image

def e_dist(a,b):
    return ((a[0]-b[0])**2+(a[1]-b[1])**2)**(1/2)

def im_gray(img):
    return cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

def disp_gray(a):
    return cv2.cvtColor(a,cv2.COLOR_GRAY2BGR)

def pim(image):
	plt.imshow(image)
    
def sharpen(img):
	kernel_sharp=np.array([[-1,-1,-1],[-1,9,-1],[-1,-1,-1]])
	sharp_img=cv2.filter2D(img,-1,kernel_sharp)
	return sharp_img

def im(image,name="image"):
	''' image is the image file willing to display , 
	name the name of window '''
	cv2.imshow(name,image)
	cv2.waitKey(0)
	cv2.destroyAllWindows()
	for i in range(5):
	    cv2.waitKey(1)

def black_image(width,height):
	''' Return a black_image with defined size'''
	return np.zeros((512,512,3),np.uint8)

def webCamImage():
	cap = cv2.VideoCapture(0)
	if (cap.isOpened()== False): 
		print("Error opening image stream or file")
	ret, frame = cap.read()
	return frame


# video functions

def videoProcessing(input_channel=0):
	''' Do define videoFunc to process the frame in it , input the input parameter'''
	cap = cv2.VideoCapture(input_channel)
	if (cap.isOpened()== False): 
	  print("Error opening video stream or file")

	while(cap.isOpened()):
	  # Capture frame-by-frame
	    ret, frame = cap.read()
	    if ret == True:
	        cv2.imshow('Frame',frame)
	        #out.write(temp)
	        if cv2.waitKey(25) & 0xFF == ord('q'):
	            cv2.destroyAllWindows()
	            for i in range(5):
	                cv2.waitKey(1)
	            break;
	  # Break the loop
	    else: 
	        break
	cap.release()
	return True

def sketch(image):
    img_gray=cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
    img_bl=cv2.GaussianBlur(img_gray,(3,3),10)
    canny=cv2.Canny(img_bl,100,5)
    # dec 100 to increase edge distance and parameters
    ret,mask=cv2.threshold(canny,70,255,cv2.THRESH_BINARY_INV)
    return mask