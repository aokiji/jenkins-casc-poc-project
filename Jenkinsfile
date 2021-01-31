@Library('pipeline-library') _

pipeline {
  agent { label 'linux' }
  stages {
    stage('build') {
      steps {
        buildCpp(target: 'target')
      }
    }
  }
}
