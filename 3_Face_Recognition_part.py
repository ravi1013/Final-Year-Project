# Full code is not added
#Face Recognition Part 

import cv2

face_classifier = cv2.CascadeClassifier('C:/Users/Jukti/anaconda3/Lib/site-packages/cv2/data/haarcascade_frontalface_default.xml')


def face_extractor(img):
    
    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    faces = face_classifier.detectMultiScale(gray,1.3,5)
    
    if faces is():
        return None
    
    for(x,y,w,h) in faces:
        cropped_face = img[y:y+h,x:x+w]
        
        return cropped_face
    

cap = cv2.VideoCapture(0)
count = 0

