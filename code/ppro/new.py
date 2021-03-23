import tensorflow as tf
import tensorflow
from tensorflow import keras


from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets('MNIST_data' , one_hot = True)

sess = tf.InteractiveSession()

x = tf.placeholder(tf.float32 , shape = [None , 784])
y = tf.placeholder(tf.float32 , shape = [None , 10])

w = tf.Variable(tf.zeros([784, 10]))
b = tf.Variable(tf.zeros([10]))

sess.run(tf.global_variables_initializer())

y_ = tf.matmul(x,w) + b

cross_entropy = tf.reduce_mean(
    tf.nn.softmax_cross_entropy_with_logits(labels = y , logits= y_)
)
train_step = tf.train.GradientDescentOptimizer(0.0001).minimize(cross_entropy)
correct_prediction = tf.equal(tf.arg_max(y_,1) ,tf.argmax(y,1))

accuracy  = tf.reduce_mean(tf.cast(correct_prediction , tf.float32))

for indexin in range(1000000):
    batch = mnist.train.next_batch(100)
    train_step.run(feed_dict = {x:batch[0] , y : batch[1]})


print(accuracy.eval(feed_dict={x:mnist.test.images, y:mnist.test.labels}))
