my best project is coln data- first we design the algorith and prove it the mathematically that why this algorithm should works
better than the classical bays and decision tree algorithm.


first we divide the data recursively until the subset of the data attribute becomes completely normalized 
then we can apply bays on these attribute subset and stored all these partial probability in the matrix
finally combine all these probability to bring the overall result, now we can classify the data points according to final probabilities.

desion tree provide various approaches to divides the data 
gini index,
gain ratio,
ID3,

classification of locally normalized data (by navie bays and decision tree):
what we did we divide the data on the basics of traits with the help of decision tree algorithms, so data is locally normalized on different
attribute, so naive bays approach will on it, now what we need to do just combine all these data to generalised the final results that can 
be done with the help of decison tree.



user can upload a image with caption , can write blogs
can send friend request , can accept a friend requst from other user.
have to delete any of his blogs

admin has right to delete any blog, 


for every user i have created a unique id, that can be used for sending and accepting friend request
for every user there is a friend list
friends list of every user can cantain multiple unique ids.

every user have it's own blog rows in the blog table which is uniquely identified with the user id';
 
while registering to the site, user have to provide his/her prefrances and on the basis of the those system will proximity matrix and 
admin can suggest whom to be friends, so that user can be frineds to other user with more and less same prefrances
