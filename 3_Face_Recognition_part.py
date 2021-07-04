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

while True:
    ret, frame = cap.read()
    if face_extractor(frame) is not None:
        count=count+1
        face = cv2.resize(face_extractor(frame),(300,300))
        face = cv2.cvtColor(face,cv2.COLOR_BGR2GRAY)
        
        file_name_path = 'C:/Users/Jukti/anaconda3/Lib/site-packages/cv2/data/Faces/user'+str(count)+'.jpg'
        cv2.imwrite(file_name_path,face)
        
        cv2.putText(face,str(count),(100,100),cv2.FONT_HERSHEY_COMPLEX,1,(0,255,0),2)
        cv2.imshow('Face Cropper',face)
    else:
        print("Face not Found")
        pass
    
    if cv2.waitKey(1)==6  or count==40:
        break
    
    cap.release()
    cv2.destroyAllWindows()
    print('Collecting Samples Complete..!!')
    