import cv2
import numpy as np

# Load the video
video_path = 'crazy.mp4'
cap = cv2.VideoCapture(video_path)

# Get the frame rate of the video
fps = int(cap.get(cv2.CAP_PROP_FPS))

# List to store the results
results = []

# Create a VideoCapture object
count = 0
while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    # Check if the frame contains red color
    red_lower = np.array([0, 0, 100])
    red_upper = np.array([100, 100, 255])
    red_mask = cv2.inRange(frame, red_lower, red_upper)
    has_red = cv2.countNonZero(red_mask) > 0

    # Check if the frame contains blue color
    blue_lower = np.array([100, 0, 0])
    blue_upper = np.array([255, 100, 100])
    blue_mask = cv2.inRange(frame, blue_lower, blue_upper)
    has_blue = cv2.countNonZero(blue_mask) > 0

    # Append 0 if red is present, 1 if blue is present
    if has_red:
        results.append(0)
    elif has_blue:
        results.append(1)
    
    count += 1

cap.release()
cv2.destroyAllWindows()
print(results)
result_text = ''.join(str(bit) for bit in results)
print(result_text)