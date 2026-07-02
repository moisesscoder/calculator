pipeline {
    agent {
        label 'cpp-build'
    }

    options {
        buildDiscarder(logRotator(numToKeepStr: '20'))
        timestamps()
        disableConcurrentBuilds()
    }

    triggers {
        pollSCM('H/5 * * * *')
    }

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Code Check') {
            steps {
                dir('calculator') {
                    sh 'make check'
                }
            }
        }

        stage('Unit Tests') {
            steps {
                dir('calculator') {
                    sh 'make unittest'
                }
            }
        }

        stage('Build') {
            steps {
                dir('calculator') {
                    sh 'make clean && make'
                }
            }
        }
    }

    post {
        success {
            archiveArtifacts artifacts: 'calculator/bin/calculator',
                             fingerprint: true,
                             allowEmptyArchive: false
        }
        failure {
            echo 'Pipeline failed — any stage error is treated as critical.'
        }
        always {
            cleanWs()
        }
    }
}
